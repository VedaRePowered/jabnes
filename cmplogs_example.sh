#!/bin/bash

# run variations of the cmplog program (compileing and running jabnes beforehand), and echo what we're doing beforehand
echo '(bash)computer:jabnes$ make # build jabnes'
make # build jabnes
echo '(bash)computer:jabnes$ ./jabnes > jabnes_nestest.log # run jabnes, and pipe the log to a file'
./jabnes > jabnes_nestest.log # run jabnes, and pipe the log to a file
echo '(bash)computer:jabnes$ ./cmplogs.lua # just run the program, defaults to nintundulator_nestest.log and jabnes_nestest.log'
./cmplogs.lua # just run the program, defaults to nintundulator_nestest.log and jabnes_nestest.log
echo '(bash)computer:jabnes$ ./jabnes > jabnes_other.log # create another log'
./jabnes > jabnes_other.log # create another log
echo '(bash)computer:jabnes$ ./cmplogs.lua nintendulator_nestest.log jabnes_nestest.log      # compare possibly-bad log from jabnes, to known good log from nintedulator, with jabnes_other this time'
./cmplogs.lua nintendulator_nestest.log jabnes_other.log      # compare possibly-bad log from jabnes, to known good log from nintedulator, with jabnes_other this time
echo '(bash)computer:jabnes$ ./cmplogs.lua nintendulator_nestest.log jabnes_nestest.log 4    # custom comparison size'
./cmplogs.lua nintendulator_nestest.log jabnes_nestest.log 4    # custom comparison size
echo '(bash)computer:jabnes$ ./cmplogs.lua nintendulator_nestest.log jabnes_nestest.log 4 65 # custom stack location (in this case p reg)'
./cmplogs.lua nintendulator_nestest.log jabnes_nestest.log 4 65 # custom stack location (in this case p reg)
