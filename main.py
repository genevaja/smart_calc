# This is a sample Python script.

# Press ⌃R to execute it or replace it with your code.
# Press Double ⇧ to search everywhere for classes, files, tool windows, actions, and settings.

import sys
from math import *
def ev_print_file(value_list):
    for str_value in value_list:
        try:
            value = eval(str_value)
            print(value)
        except Exception as Ex:
            print (str(Ex))
        # Use a breakpoint in the code line below to debug your script.

def ev_print_console(str_value):
    try:
        value = eval(str_value)
        print(value)
    except Exception as Ex:
        print (str(Ex))
        # Use a breakpoint in the code line below to debug your script.

def parcer_file():
    with open("f.txt", 'r') as f:
        return f.readlines()

# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    #print(sys.argv[1])
    #ev_print(parcer_file())
    ev_print_console(sys.argv[1])

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
