// Data    :2016.07.19
// Author  :yqtao

/*******************************************************************
We are playing the Guess Game. The game is as follows:
I pick a number from 1 to n. You have to guess which number I picked.
Every time you guess wrong, I'll tell you whether the number is higher or lower.
You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):
-1 : My number is lower
1 : My number is higher
0 : Congrats! You got it!
Example:
n = 10, I pick 6.
Return 6.
****************************************************************************/
//this prolem we use binary search
//the very careful is meanNumber = (maxNumber - minNumber) / 2 + minNumber
//and not mid=(start+end)/2,because it can overflow
int guess(int num);
int guessNumber(int n) {
	int maxNumber = n, minNumber = 1;
	while (true) {
		int meanNumber = (maxNumber - minNumber) / 2 + minNumber;
		int res = guess(meanNumber);
		if (res == 0) {
			return meanNumber;
		}
		else if (res == 1) {
			minNumber = meanNumber + 1;
		}
		else {
			maxNumber = meanNumber - 1;
		}
	}
}