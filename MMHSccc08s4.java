/*
Twenty-four is a popular card game designed to be played by four players. Each player is dealt a deck of cards, 
which are kept face down. On every turn, each of the four players turns over the top card of his or her deck, so 
that it is visible to all. The goal is to find an arithmetic expression using the values of the cards (with A meaning 1, 
J meaning 11, Q meaning 12, and K meaning 13) that evaluates to the number 24. For example, one possible expression would be:
((A * K)- J) * Q
((1*13)-11) * 12
The first player to find such an expression wins the turn, and adds all four cards to the bottom of his or her deck.
Each valid arithmetic expression must use all four cards, and must combine their values using addition, subtraction,
multiplication, or division. Parentheses are allowed to specify precedence of operations. Juxtaposing cards to make multiple-digit decimal numbers is not allowed (e.g. you cannot place the cards 2 and 4 beside each other to make 24). Non-integer quotients of division are also not allowed, even as a partial result (of a subexpression of the overall expression).
In some cases, the players may take a very long time to find an expression evaluating to 24. In fact, in some cases, no such 
expression exists. Your task is to determine, given four cards, an expression that evaluates to the largest number less than 
or equal to 24.
*/
// CCC 2008 S4: TwentyFour
// the idea here is:
//    Generate all possible answers.
//    look for biggest <= 24. done. :-)
// to generate all answers I do all possible operations
// for example if the hand is: 2 6 8 10
// then I go thru ALL permutations of two numbers and do
// the possible operations, creating new hands of 3 numbers.
// In the above example I'd get:
//  8 8 10   (added 2+6)
//  -4 8 10  (subtracted 2-6)
//  12 8 10  (multiplied 2*6)  (couldn't divide 2/60
//  10 6 10  (added 2+8)
//  -6 6 10  (subtracted 2-8)
//  ...
// in this way a hand of 4 become many hands of 3 then those hands of 3 become hands of 2 and then 1.
// finally it looks for the biggest number <= 24.
// I calculated a max possible number of hands as:
//   1 hand of 4    (given)
//  48 hands of 3   ( = 12 perumtations * 4 operations)
// 1152 hands of 2  ( = 48 hands * 6 permutations * 4 operations)
// 9216 hands of 1  ( = 1152 * 2 numbers * 4 operations)
import java.awt.*;
import hsa.*;
public class CCC2008S4TwentyFour
{
    static Console c;
    // this takes a group of handSize numbers and combines 2 of the numbers
    // using all operations in all possible ways, creating a new series
    // of hands, with one fewer numbers in each.
    static int doOperations (int[] hand, int handSize, int[] [] newHand, int k)
    {
	for (int i = 0 ; i < handSize ; i++)
	    for (int j = 0 ; j < handSize ; j++)
		if (i != j)
		{
		    // do +
		    newHand [k] [0] = hand [i] + hand [j];
		    // fill the hand with the other numbers
		    int q = 1;
		    for (int p = 0 ; p < handSize ; p++)
			if (!(p == i || p == j))
			    newHand [k] [q++] = hand [p];
		    k++;

		    // do -
		    newHand [k] [0] = hand [i] - hand [j];
		    // fill the hand with the other numbers
		    q = 1;
		    for (int p = 0 ; p < handSize ; p++)
			if (!(p == i || p == j))
			    newHand [k] [q++] = hand [p];
		    k++;

		    // do *
		    newHand [k] [0] = hand [i] * hand [j];
		    // fill the hand with the other numbers
		    q = 1;
		    for (int p = 0 ; p < handSize ; p++)
			if (!(p == i || p == j))
			    newHand [k] [q++] = hand [p];
		    k++;

		    // do / if you can
		    if (hand [j] != 0 && hand [i] % hand [j] == 0)
		    {
			newHand [k] [0] = hand [i] / hand [j];
			// fill the hand with the other numbers
			q = 1;
			for (int p = 0 ; p < handSize ; p++)
			    if (!(p == i || p == j))
				newHand [k] [q++] = hand [p];
			k++;
		    }
		}
	return k;
    }

  public static void main (String[] args)
    {
	int n, size, newSize;
	int[] [] hand, newHand;
	c = new Console ();
	TextInputFile f = new TextInputFile ("s4.5.in");
	n = f.readInt ();
	for (int i = 0 ; i < n ; i++)
	{
	    newHand = new int [1] [4];
	    newHand [0] [0] = f.readInt ();
	    newHand [0] [1] = f.readInt ();
	    newHand [0] [2] = f.readInt ();
	    newHand [0] [3] = f.readInt ();
	    newSize = 1;

	    // generate all the hands, size 4 to 3, 3 to 2 and 2 to 1.
	    for (int k = 4 ; k > 1 ; k--)
	    {
		size = newSize;
		hand = newHand;
		newHand = new int [10000] [3];
		newSize = 0;
		for (int j = 0 ; j < size ; j++)
		    newSize = doOperations (hand [j], k, newHand, newSize);
	    }
	    // find the biggest <= 24 and print it.
	    size = newSize;
	    int biggest = 0;
	    for (int j = 0 ; j < size && biggest < 24 ; j++)
		if (newHand [j] [0] > biggest && newHand [j] [0] <= 24)
		    biggest = newHand [j] [0];
	    c.println (biggest);
	}
    }
}
