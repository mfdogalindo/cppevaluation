# Producer/Consumer pattern in Linux to sort input

## Download and compiling

Copy repo:

```
git clone https://github.com/mfdogalindo/cppevaluation.git ~/ProducerConsumer
```

if you do not have GCC installed in Ubuntu :

```
sudo apt install binutils
```

finally, mount folder and compile:

```
cd ~/ProducerConsumer
make
```



## Usage

./ProducerConsumer  arg1 arg2 arg3 

* arg1: Path of input file (mandatory)

* arg2: Path of output file (./out.txt is default value)

* arg3: Sort algorithm selector

  * <strong>-q</strong> or <strong>--quick</strong> : Quicksort (default) https://en.wikipedia.org/wiki/Quicksort

    This is a classic sorting algorithm, its performance in the worst case is O (n^2) and on average O (n log n) which is also its best case. That is why it is selected, as it has a stability in its computational cost, which allows estimating its performance over time.

  * <strong>-g</strong> or <strong>--gnome</strong> : Gnome sort https://en.wikipedia.org/wiki/Gnome_sort

    This is a sort algorithm similar to insertion sort, its performance in the worst case and on average is O(n^2) and in the best case O(n). For this reason gnome is an interesting algorithm because, although on average its performance is worse than quick, it is possible that under appropriate conditions the algorithm offers superior performance in large process.

<strong>example:</strong>

 ``` 
./ProducerConsumer test/test_file.txt test/out.txt -q

Sort method: quick
WARNING! Line 11 invalid
Success!
 ```





