#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct card
{
  int symbol;
  int num;
};

const int SPADE = 1;
const int HEART = 2;
const int DIAMOND = 3;
const int CLUB = 4;
const int size = 52;
const int color = 4;

int
main (void)
{
  //instructions
  printf
    ("You will be given 4 cards from a standard deck. You can use the opreations +, -, * and / in any order to perform on those four numbers. The goal is using all 4 numbers and those operations to get the result of 24. Card A is consider as 1, Card J is consider as 11,Card Q is consider as 12 and Card K is consider as 13.\n");
  // cards initialize
  struct card *standard_deck = malloc (sizeof (struct card) * size);
  int symbols[4] = { SPADE, HEART, DIAMOND, CLUB };
  int pos = 0;
  for (int c = 0; c < color; c++)
    {
      for (int i = 0; i < size / color; i++)
	{
	  pos = i + c * (size / color);
	  standard_deck[pos].num = i + 1;
	  standard_deck[pos].symbol = symbols[c];
	}
    }
  srand ((unsigned) time (NULL));
  int r = 0;
  int used = 0;
  const int new = 4;
  int used_cards[4] = { 0 };
  for (int i = 0; i < 4; i++)
    {
      used_cards[i] = -1;
    }
  // hand out 4 cards
  for (int i = 0; i < new; i++)
    {
      r = rand ();
      r = r % size;
      for (int c = 0; c <= used; c++)
	{
	  if (used_cards[c] == r)
	    {
	      i = i - 1;
	      break;
	    }
	  else
	    {
	      used_cards[used] = r;
	      used = used + 1;
	      break;
	    }
	}
    }
  // print four cards
  printf ("Your cards are: \n");
  for (int i = 0; i < 4; i++)
    {
      if (standard_deck[used_cards[i]].symbol == SPADE)
	{
	  printf ("SPADE ");
	}
      else if (standard_deck[used_cards[i]].symbol == CLUB)
	{
	  printf ("CLUB ");
	}
      else if (standard_deck[used_cards[i]].symbol == DIAMOND)
	{
	  printf ("DIAMOND ");
	}
      else if (standard_deck[used_cards[i]].symbol == HEART)
	{
	  printf ("HEART ");
	}
      if (standard_deck[used_cards[i]].num == 1)
	{
	  printf ("A\n");
	}
      else if (standard_deck[used_cards[i]].num == 11)
	{
	  printf ("J\n");
	}
      else if (standard_deck[used_cards[i]].num == 12)
	{
	  printf ("Q\n");
	}
      else if (standard_deck[used_cards[i]].num == 13)
	{
	  printf ("K\n");
	}
      else
	{
	  printf ("%d\n", standard_deck[used_cards[i]].num);
	}
    }
  // all possible combination of numbers
  const double i_1 = standard_deck[used_cards[0]].num;
  const double i_2 = standard_deck[used_cards[1]].num;
  const double i_3 = standard_deck[used_cards[2]].num;
  const double i_4 = standard_deck[used_cards[3]].num;
  double *group[24] = { };
  double aon1[4] = { i_1, i_2, i_3, i_4 };
  group[0] = aon1;
  double aon2[4] = { i_1, i_2, i_4, i_3 };
  group[1] = aon2;
  double aon3[4] = { i_1, i_3, i_2, i_4 };
  group[2] = aon3;
  double aon4[4] = { i_1, i_3, i_4, i_2 };
  group[3] = aon4;
  double aon5[4] = { i_1, i_4, i_2, i_3 };
  group[4] = aon5;
  double aon6[4] = { i_1, i_4, i_3, i_2 };
  group[5] = aon6;
  double aon7[4] = { i_2, i_1, i_3, i_4 };
  group[6] = aon7;
  double aon8[4] = { i_2, i_1, i_4, i_3 };
  group[7] = aon8;
  double aon9[4] = { i_2, i_3, i_1, i_4 };
  group[8] = aon9;
  double aon10[4] = { i_2, i_3, i_4, i_1 };
  group[9] = aon10;
  double aon11[4] = { i_2, i_4, i_1, i_3 };
  group[10] = aon11;
  double aon12[4] = { i_2, i_4, i_3, i_1 };
  group[11] = aon12;
  double aon13[4] = { i_3, i_1, i_2, i_4 };
  group[12] = aon13;
  double aon14[4] = { i_3, i_1, i_4, i_2 };
  group[13] = aon14;
  double aon15[4] = { i_3, i_2, i_4, i_1 };
  group[14] = aon15;
  double aon16[4] = { i_3, i_2, i_1, i_4 };
  group[15] = aon16;
  double aon17[4] = { i_3, i_4, i_1, i_2 };
  group[16] = aon17;
  double aon18[4] = { i_3, i_4, i_2, i_1 };
  group[17] = aon18;
  double aon19[4] = { i_4, i_1, i_2, i_3 };
  group[18] = aon19;
  double aon20[4] = { i_4, i_1, i_3, i_2 };
  group[19] = aon20;
  double aon21[4] = { i_4, i_2, i_1, i_3 };
  group[20] = aon21;
  double aon22[4] = { i_4, i_2, i_3, i_1 };
  group[21] = aon22;
  double aon23[4] = { i_4, i_3, i_1, i_2 };
  group[22] = aon23;
  double aon24[4] = { i_4, i_3, i_2, i_1 };
  group[23] = aon24;
  // all possible combination of operations
  char yn = ' ';
  char *op_group[64] = { };
  char op[4] = { '+', '-', '*', '/' };
  int count_g = 0;
  for (int a = 0; a < 4; a++)
    {
      for (int b = 0; b < 4; b++)
	{
	  for (int c = 0; c < 4; c++)
	    {
	      char *oper_group = malloc (sizeof (char) * 3);
	      oper_group[0] = op[a];
	      oper_group[1] = op[b];
	      oper_group[2] = op[c];
	      op_group[count_g] = oper_group;
	      count_g = count_g + 1;
	    }
	}
    }
  double resulttt = 0;
  int c_n = 0;
  int c_o = 0;
  for (int i = 0; i < 24; i++)
    {
      for (int b = 0; b < 64; b++)
	{
	  if (op_group[b][0] == '+')
	    {
	      resulttt = group[i][0] + group[i][1];
	    }
	  else if (op_group[b][0] == '-')
	    {
	      resulttt = group[i][0] - group[i][1];
	    }
	  else if (op_group[b][0] == '*')
	    {
	      resulttt = group[i][0] * group[i][1];
	    }
	  else if (op_group[b][0] == '/')
	    {
	      resulttt = group[i][0] / group[i][1];
	    }
	  if (op_group[b][1] == '+')
	    {
	      resulttt = resulttt + group[i][2];
	    }
	  else if (op_group[b][1] == '-')
	    {
	      resulttt = resulttt - group[i][2];
	    }
	  else if (op_group[b][1] == '*')
	    {
	      resulttt = resulttt * group[i][2];
	    }
	  else if (op_group[b][1] == '/')
	    {
	      resulttt = resulttt / group[i][2];
	    }
	  if (op_group[b][2] == '+')
	    {
	      resulttt = resulttt + group[i][3];
	    }
	  else if (op_group[b][2] == '-')
	    {
	      resulttt = resulttt - group[i][3];
	    }
	  else if (op_group[b][2] == '*')
	    {
	      resulttt = resulttt * group[i][3];
	    }
	  else if (op_group[b][2] == '/')
	    {
	      resulttt = resulttt / group[i][3];
	    }
	  if (resulttt == 24)
	    {
	      c_o = b;
	      break;
	    }
	}
      if (resulttt == 24)
	{
	  c_n = i;
	  break;
	}
    }
  int w = group[c_n][0];
  int x = group[c_n][1];
  int y = group[c_n][2];
  int z = group[c_n][3];
  printf ("Enter 'y' until you want to see a possible answer.\n");
  int scan = 0;
  while (scan != 1)
    {
      scan = scanf ("%c", &yn);
    }
  if (resulttt == 24)
    {
      if (yn == 'y')
	{
	  printf ("24 = (( %d %c %d ) %c %d ) %c %d \n", w, op_group[c_o][0],
		  x, op_group[c_o][1], y, op_group[c_o][2], z);
	}
    }
  else
    {
      //tree 2
      double resulttt1 = 0;
      for (int i = 0; i < 24; i++)
	{
	  for (int b = 0; b < 64; b++)
	    {
	      if (op_group[b][0] == '+')
		{
		  resulttt1 = group[i][0] + group[i][1];
		}
	      else if (op_group[b][0] == '-')
		{
		  resulttt1 = group[i][0] - group[i][1];
		}
	      else if (op_group[b][0] == '*')
		{
		  resulttt1 = group[i][0] * group[i][1];
		}
	      else if (op_group[b][0] == '/')
		{
		  resulttt1 = group[i][0] / group[i][1];
		}
	      double resulttt2 = 0;
	      if (op_group[b][1] == '+')
		{
		  resulttt2 = group[i][2] + group[i][3];
		}
	      else if (op_group[b][1] == '-')
		{
		  resulttt2 = group[i][2] - group[i][3];
		}
	      else if (op_group[b][1] == '*')
		{
		  resulttt2 = group[i][2] * group[i][3];
		}
	      else if (op_group[b][1] == '/')
		{
		  resulttt2 = group[i][2] / group[i][3];
		}
	      if (op_group[b][2] == '+')
		{
		  resulttt = resulttt1 + resulttt2;
		}
	      else if (op_group[b][2] == '-')
		{
		  resulttt = resulttt1 - resulttt2;
		}
	      else if (op_group[b][2] == '*')
		{
		  resulttt = resulttt1 * resulttt2;
		}
	      else if (op_group[b][2] == '/')
		{
		  resulttt = resulttt1 / resulttt2;
		}
	      if (resulttt == 24)
		{
		  c_o = b;
		  break;
		}
	    }
	  if (resulttt == 24)
	    {
	      c_n = i;
	      break;
	    }
	}
      int w = group[c_n][0];
      int x = group[c_n][1];
      int y = group[c_n][2];
      int z = group[c_n][3];
      if (resulttt == 24)
	{
	  if (yn == 'y')
	    {
	      printf ("24 = (%d %c %d) %c (%d %c %d)\n", w, op_group[c_o][0],
		      x, op_group[c_o][2], y, op_group[c_o][1], z);
	    }
	}
      else
	{
	  if (yn == 'y')
	    {
	      printf ("no correct answer\n");
	    }
	}
    }
  printf ("Thanks for playing!");
  free (standard_deck);
  for (int i = 0; i < 64; i++)
    {
      free (op_group[i]);
    }
}
