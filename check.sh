make

./Oracle 2> test1; ./pathfinder 2> test2; diff test1 test2 > diffresult1; 
echo difference for \"COMMAND-LINE ARGUMENTS\" is:
cat -e diffresult1
echo '\n'

./Oracle ISLANDS 2> test1; ./pathfinder ISLANDS 2> test2; diff test1 test2 > diffresult1;
echo difference for \"ISLANDS\" is:
cat -e diffresult1
echo '\n'

./Oracle EMPTY 2> test1; ./pathfinder EMPTY 2> test2; diff test1 test2 > diffresult1;
echo difference for \"EMPTY\" is:
cat -e diffresult1
echo '\n'

echo "4f
Greenland-Bananal,8
Fraser-Greenland,10
Bananal-Fraser,3
Java-Fraser,5
" > invalid1

./Oracle invalid1 2> test1; ./pathfinder invalid1 2> test2; diff test1 test2 > diffresult1;
echo difference for \"INVALID1\" is:
cat -e diffresult1
echo '\n'

echo "4
Greenland-Bananal,8
Fraser--Greenland,10
Bananal-Fraser,3
Java-Fraser,5" > invalid2

./Oracle invalid2 2> test1; ./pathfinder invalid2 2> test2; diff test1 test2 > diffresult1;
echo difference for \"INVALID2\" is:
cat -e diffresult1
echo '\n'

echo "3
Greenland-Bananal,8
Fraser-Greenland,10
Bananal-Fraser,3
Java-Fraser,5" > invalid3

./Oracle invalid3 2> test1; ./pathfinder invalid3 2> test2; diff test1 test2 > diffresult1;
echo difference for \"INVALID3\" is:
cat -e diffresult1
echo '\n'

echo "3
Blade-Wizard,1
Drive-Blade,1
Wizard-Wizard,1" > invalid4

./Oracle invalid4 2> test1; ./pathfinder invalid4 2> test2; diff test1 test2 > diffresult1;
echo difference for \"INVALID4\" is:
cat -e diffresult1
echo '\n'

echo "3
Blade-Wizard,1
Drive-Blade,1
Blade-Drive,2
Wizard-Drive,1" > invalid5

./Oracle invalid5 2> test1; ./pathfinder invalid5 2> test2; diff test1 test2 > diffresult1;
echo difference for \"INVALID5\" is:
cat -e diffresult1
echo '\n'

echo "3
Blade-Wizard,1
Drive-Blade,2147483647
Wizard-Drive,1" > invalid6

./Oracle invalid6 2> test1; ./pathfinder invalid6 2> test2; diff test1 test2 > diffresult1;
echo difference for \"INVALID6\" is:
cat -e diffresult1
echo '\n'

echo "4
Greenland-Bananal,8
Fraser-Greenland,10
Bananal-Fraser,3
Java-Fraser,5" > example1

./Oracle example1 > test1; ./pathfinder example1 > test2; diff test1 test2 > diffresult1;
echo difference for \"EXAMPLE1\" is:
cat -e diffresult1
echo '\n'

echo "5
A-B,11
A-C,10
B-D,5
C-D,6
C-E,15
D-E,4" > example2

./Oracle example2 > test1; ./pathfinder example2 > test2; diff test1 test2 > diffresult1;
echo difference for \"EXAMPLE2\" is:
cat -e diffresult1
echo '\n'

echo "3
Blade-Wizard,1
Drive-Blade,1
Wizard-Drive,1" > easy

./Oracle easy > test1; ./pathfinder easy > test2; diff test1 test2 > diffresult1;
echo difference for \"EASY\" is:
cat -e diffresult1
echo '\n'

echo "4
One-Two,1
Zero-Eight,8
Two-Zero,2" > medium
./Oracle medium > test1; ./pathfinder medium > test2; diff test1 test2 > diffresult1;
echo difference for \"MEDIUM\" is:
cat -e diffresult1
echo '\n'

echo "8
Kyiv-Kharkiv,471
Nikopol-Kharkiv,340
Kyiv-Warsaw,766
Kyiv-Paris,2403
Kyiv-Prague,1141
Kyiv-Singapore,11864
Kyiv-Tokyo,11079" > hard
./Oracle hard > test1; ./pathfinder hard > test2; diff test1 test2 > diffresult1;
echo difference for \"HARD\" is:
cat -e diffresult1
echo '\n'

echo "7
Home-BusStop,4
BusStop-Work,7
Home-Taxi,1
Metro-Home,6
Taxi-Work,10
Work-Gym,2
Metro-Work,8
Taxi-Gym,12
BusStop-Park,18
Park-Metro,16" > hardest
./Oracle hardest > test1; ./pathfinder hardest > test2; diff test1 test2 > diffresult1;
echo difference for \"HARDEST\" is:
cat -e diffresult1
echo '\n'

rm -rf test* diffresult1 invalid* easy* hard* medium empty examp*
