import fileinput
 
DISPLAY = '''
     AAAAAAAAA
    FF       BB
    FF       BB
    FF       BB
    FF       BB
     GGGGGGGG
   EE       CC
   EE       CC
   EE       CC
   EE       CC
    DDDDDDDDD
''' 

# STFW: ANSI Escape Code
CLEAR = '\033[2J\033[1;1f'
BLOCK = {
    0: '\033[37m░\033[0m',
    1: '\033[31m█\033[0m',
}

for line in fileinput.input():
    # Load "A=0; B=1; ..." to current context
    exec(line)

    # Render the seven-segment display
    pic = DISPLAY
    for seg in set(DISPLAY):
        if seg.isalpha():
            val = globals()[seg]  # 0 or 1
            pic = pic.replace(seg, BLOCK[val])

    # Clear screen and display
    print(CLEAR + pic)
