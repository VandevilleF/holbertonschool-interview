#!/usr/bin/python3
def validUTF8(data):
    """ Determines if a given data set represents a valid UTF-8 encoding
    """
    count = 0

    for num in data:
        byte = num & 0xFF

        if count == 0:
            if (byte >> 7) == 0b0:  # 1 octet (0xxxxxxx)
                continue
            elif (byte >> 5) == 0b110:  # 2 octets (110xxxxx)
                count = 1
            elif (byte >> 4) == 0b1110:  # 3 octets (1110xxxx)
                count = 2
            elif (byte >> 3) == 0b11110:  # 4 octets (11110xxx)
                count = 3
            else:
                return False  # Octet invalide
        else:
            if (byte >> 6) != 0b10:
                return False
            count -= 1

    return count == 0
