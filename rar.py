import os
import time


#source = (r'D:\照片',r'D:\仙剑4')
source = r'D:\照片 D:\仙剑4'
#source = r'D:\照片'
target_dir = 'F:\\backup\\'
now = time.strftime('%H%M%S')
today = target_dir + time.strftime('%m%d')

if not os.path.exists(target_dir):
    os.mkdir(target_dir)

if not os.path.exists(today):
    os.mkdir(today)
    print('Successfully created dirtionary %s' %today)

target = today + os.sep + now + '.rar'

rar_command = "winrar a {0} {1}".format(target, source)

if os.system(rar_command) == 0:
    print('Successful backup to %s'%target)
else:
    print(rar_command)
    print('Backup Failed')
