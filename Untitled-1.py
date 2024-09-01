import string

def strToBin(string: str):
    binStr = ""
    
    for i in range(len(string)):
        subStr = ""
        left = 8
        ch = ord(string[i])

        while(ch > 0):
            subStr += chr(int(ch % 2) + 48)
            ch = int(ch/2)
            left -= 1

        subStr += '0' * left
        subStr = subStr[::-1]
        subStr += " "
        binStr += subStr

    return binStr


if __name__ == "__main__":
    studentDict = {"name": "Pedro", "age": 24, "grade": 10.0, "registration": "202304084751"}
    print(strToBin(studentDict.get("name")))