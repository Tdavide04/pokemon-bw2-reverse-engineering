def calculate_id_as_uint(tid: int, sid: int) -> int:
  """
  Calculate the IDAsUInt given a Trainer ID (TID) and a Secret ID (SID).

  IDAsUInt is a 32-bit integer where:
    - the upper 16 bits contain the SID
    - the lower 16 bits contain the TID

  :param tid: Trainer ID (value from 0 to 65535)
  :param sid: Secret ID (value from 0 to 65535)
  :return: IDAsUInt (32-bit integer)
  """
  return (sid << 16) | tid

# Example
tid = 42931
sid = 42151
idasuint = calculate_id_as_uint(tid, sid)
print(f"IDAsUInt: {idasuint}")  
