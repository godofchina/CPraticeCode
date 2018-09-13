#include <stdio.h>

#include <string.h>

 int main()

         {

                      int m = 3;

                           int n = 7;

                                   int a[7] = {1,2,3,4,5,6,7};

                                           int i;

                                                   int j;

                                                        for(i = 0; i < n; i++)

                                                                     {

                                                                                      a[i] = i+1;

                                                                                           }

                                                             while (n > 1)

                                                                          {

                                                                                           i = (i + m - 1) % n;

                                                                                                    printf("第一个出圈的是%d\n",a[i]);

                                                                                                             for(j = i+1; j < n; j++)

                                                                                                                              {

                                                                                                                                                   a[j-1] = a[j];

                                                                                                                                                            }

                                                                                                                      n--;

                                                                                                                               if(i == n)

                                                                                                                                                {

                                                                                                                                                                     i = 0;

                                                                                                                                                                              }

                                                                                                                                    }

                                                                  printf("最后剩下的是%d\n", a[i]);

                                                                       return 0;

 }
