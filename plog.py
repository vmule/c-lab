import os
import sys

if len(sys.argv) < 2:
  print('give me some pid...')
  exit(1)

pid_path = os.path.join('/proc', sys.argv[1], 'fd/')


for _, _, files in os.walk(pid_path, followlinks=True):
  if len(files):
    print("Log path(s):")
    for f in files:
      fd = os.path.join(pid_path, f)
      real_file = os.path.realpath(fd)
      if "log" in real_file:
        print real_file
  else:
    print("No log(s) found.\n")
    exit(1)

exit(0)
