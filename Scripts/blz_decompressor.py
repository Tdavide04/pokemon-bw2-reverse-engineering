import struct, sys, os

# BLZ Compression Constants
BL_THRESHOLD = 2    # Minimum match length for compression
BLZ_N = 0x1002      # Maximum sliding window size
BLZ_F = 0x12        # Maximum match length
RAW_MAXIM = 0x00FFFFFF
BLZ_MINIM = 0x00000004

class BLZConverter:
    def __init__(self, arm9=False):
        self.arm9 = arm9

    def crc16(self, data: bytes) -> int:
        """Standard CRC16-ANSI calculation (often used for validation in NDS headers)."""
        crc = 0xFFFF
        for byte in data:
            crc ^= byte
            for _ in range(8):
                if crc & 1:
                    crc = (crc >> 1) ^ 0xA001
                else:
                    crc >>= 1
        return crc & 0xFFFF

    def invert(self, data: bytearray):
        """Inverts the byte order. BLZ processes data from end to start."""
        data.reverse()

    def search(self, raw_buffer, current_pos, raw_end_idx):
        """Searches for repeated patterns in the sliding window (LZSS encoding logic)."""
        best_len = BL_THRESHOLD
        best_pos = 0
        
        # Limit search window to current position or max window size
        max_offset = min(current_pos, BLZ_N)
        
        for pos in range(3, max_offset + 1):
            length = 0
            # Check for matches between current data and previous data in the window
            while (length < BLZ_F and 
                   current_pos + length < raw_end_idx and 
                   length < pos and
                   raw_buffer[current_pos + length] == raw_buffer[current_pos + length - pos]):
                length += 1
            
            # If a longer match is found, update best length/position
            if length > best_len:
                best_len = length
                best_pos = pos
                if length == BLZ_F:
                    break
        return best_len, best_pos

    def decode(self, filename):
        """Main decompression logic for BLZ compressed files."""
        print(f"- decoding '{filename}'", end="")
        with open(filename, "rb") as f:
            pak_buffer = bytearray(f.read())

        pak_len = len(pak_buffer)
        # Extract the length of the decompressed data suffix from the last 4 bytes
        inc_len = struct.unpack("<I", pak_buffer[-4:])[0]

        if inc_len == 0:
            print(", WARNING: not coded file!")
            raw_buffer = pak_buffer
        else:
            # BLZ footer structure: [HeaderLen(1b)][EncLen(3b)][IncLen(4b)]
            hdr_len = pak_buffer[-5]
            # Encoded length is stored in the 3 bytes before the header length
            enc_len = struct.unpack("<I", pak_buffer[-8:-4])[0] & 0x00FFFFFF
            
            dec_len = pak_len - enc_len # Length of the uncompressed prefix
            actual_pak_len = enc_len - hdr_len # Actual data to process
            raw_len = dec_len + enc_len + inc_len # Total size after decompression
            
            raw_buffer = bytearray(raw_len)
            # Copy the already uncompressed part (beginning of the file)
            raw_buffer[0:dec_len] = pak_buffer[0:dec_len]
            
            # Extract and invert the compressed section for processing
            compressed_part = pak_buffer[dec_len : dec_len + actual_pak_len]
            self.invert(compressed_part)
            
            pak_idx = 0
            raw_idx = dec_len
            mask = 0
            flags = 0
            
            # LZSS Decoding Loop
            while raw_idx < raw_len:
                mask >>= 1
                if mask == 0:
                    # Read new flag byte (8 bits indicating if next chunks are compressed)
                    if pak_idx >= len(compressed_part): break
                    flags = compressed_part[pak_idx]
                    pak_idx += 1
                    mask = 0x80

                # Bit 0: Raw byte (literal)
                if not (flags & mask):
                    if pak_idx >= len(compressed_part): break
                    raw_buffer[raw_idx] = compressed_part[pak_idx]
                    raw_idx += 1
                    pak_idx += 1
                # Bit 1: Compressed reference (Match)
                else:
                    if pak_idx + 1 >= len(compressed_part): break
                    # Get 16-bit match info (Length and Offset)
                    p = (compressed_part[pak_idx] << 8) | compressed_part[pak_idx+1]
                    pak_idx += 2
                    
                    # Length: top 4 bits + threshold
                    length = (p >> 12) + BL_THRESHOLD + 1
                    # Offset: bottom 12 bits + offset constant
                    offset = (p & 0xFFF) + 3
                    
                    # Copy matching bytes from the sliding window
                    for _ in range(length):
                        if raw_idx < raw_len:
                            raw_buffer[raw_idx] = raw_buffer[raw_idx - offset]
                            raw_idx += 1

            # Invert the processed suffix back to correct orientation
            suffix = raw_buffer[dec_len:]
            self.invert(suffix)
            raw_buffer[dec_len:] = suffix

        # Generate the new filename (e.g., arm9.bin -> arm9_dec.bin)
        name, ext = os.path.splitext(filename)
        out_filename = f"{name}_dec{ext}"

        # Write the decompressed data to the new file
        with open(out_filename, "wb") as f:
            f.write(raw_buffer)
        
        print(f"\nDecompression complete! File saved as: {out_filename}")

    
if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python blz_decompressor.py <filename>")
        print("Example: python blz_decompressor.py w2_arm9.bin")
    else:
        # The filename is now the first argument after the script name
        file_path = sys.argv[1]
        
        if not os.path.exists(file_path):
            print(f"Error: File '{file_path}' not found.")
            sys.exit(1)
            
        # Automatically detect if it's an arm9 file to set internal flags
        is_arm9 = "9" in file_path or "arm9" in file_path.lower()
        
        converter = BLZConverter(arm9=is_arm9)
        converter.decode(file_path)