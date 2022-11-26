#include <stdio.h>

int main(void){

  char alf[] = "IVXLCDM";
  int oldest_id = -1, old_id = -1, id = -1, k = 0, old_k = 0, check = 0, check_num = 1, n = 0, res = 0;
  for (char ch = getchar(); ch != EOF; ch = getchar())
  {
    check = 0;
    oldest_id = old_id;
    old_id = id;

    for (int i =  0; i < sizeof(alf)/sizeof(alf[0]); i++)
    {
      if (alf[i] == ch)
      {
        check = 1;
        id = i;
      }
    }
    if ((ch != ' ') && (ch != ',') && (ch != '  ') && (ch != '\n') && (check == 0))
    {
      //printf("lol %c ", ch);
      check_num = 0;
      id = -1;
      check = 1;
    }
    else if (((ch == ' ') || (ch == ',') || (ch == '  ') || (ch == '\n')) && (n == 0))
    {
      check_num = 0;
      //printf("%d\n", check_num);
      res += check_num;
      id = -1;
      check_num = 1;
      old_k = 0;
      continue;
    }



    if (check == 1)
    {
      n ++;
      if ((old_id != -1) && (old_id == id))
        k++;
      else
      {
        old_k = k;
        k = 1;
      }

      if ((old_id != -1) && (old_id < id) && (old_k >= 2))
      {
        check_num = 0;
        //printf("a");
      }
      if (k > 3)
      {
        check_num = 0;
          //printf("b");
      }
      if ((old_id != -1) && (old_id != id) && (oldest_id != -1) && (id == oldest_id) && (id < old_id))
      {
        check_num = 0;
          //printf("c");
      }
      if ((old_id != -1) && (old_id != id) && (old_id == 1) && (oldest_id != -1)) // ДОРАБОТАТЬ
      {
        check_num = 0;
          //printf("c");
      }
      if ((old_id != -1) && (old_id == id) && (id == 1))
      {
        check_num = 0;
          //printf("d");
      }

      //printf("%d,%d,%d  ", k, id, old_id);
    }

    else
    {
      n = 0;
      //printf("%d\n", check_num);
      res += check_num;
      id = -1;
      check_num = 1;
      old_k = 0;
    }
    //printf("%c",ch);
  }
  printf("%d\n", res);
}
