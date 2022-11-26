#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct match_details
{
  char name[25];                                                   //  -
  char venue[25];                                                  //   |  > Stucture match_details is created to store
  char date[20];                                                   //   |    variables of different datatypes which
  char time[20];                                                   //   |    are common to a particular match.
  char tname1[25], tname2[25];                                     //   |    
  char tossw[25];                                                  //   |  > Array size 100 denotes that  
  char twc[5];                                                     //   |    100 scoresheets can be created.
  char wname[25];                                                  //   |                              
  int tscore1, tscore2;                                            //   |    
  int twickets1, twickets2;                                        //  -
} a[100];

struct team_details
{
  char batname[25];                                                //  -
  int batruns;                                                     //   |  > Structure team_details is created to store
  int batballs;                                                    //   |    variables of different datatypes which
  float strike;                                                    //   |    are common to a particular team.  
  char bowlname[25];                                               //   |   
  int bowlruns;                                                    //   |  > t1,t2 are 2D arrays in which       
  int extras;                                                      //   |    100 rows corresponds to 100 maths and 
  float overs;                                                     //   |    11 columns corresponds to 11 players in a team 
  int wickets;                                                     //   |   
  float eco;                                                       //   |  > variables t1 and t2 corresponds to  
} t1[100][11],t2[100][11];                                         //  -     two teams in a particular match.

int new();
void view(int);
void edit(int);

int main()
{   
  int choice,g,z=0,l,i,ssn;
  do
  {                                                
    printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("                                CRICKET SCORESHEET CREATOR\n");                                       // main menu.
    printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\nWELCOME, Please choose your action.\n\n");
    printf("1. CREATE NEW SCORESHEET.\n");
    printf("2. VIEW A CREATED SCORESHEET.\n");
    printf("3. EDIT A CREATED SCORESHEET.\n");
    printf("4. Exit.\n");
    c:
    scanf("%d",&choice);
    switch(choice)                                                                        
    {
      case 1:                                                                          // case for creating new scoresheet.
          i=new();                                                                     // calling the new() function.
          break;
      case 2:                                                                          // case for viewing a edited scoresheet.
          if(strlen(a[0].name)==0)
          printf("\nPlease create scoresheet first.\n\n");                             // error message is displayed if no scoresheet is created.
          else
            {   
              do
              { 
                printf("\n------------------------------------------------------------------------------------------\n");
                printf("                                    VIEW SCORESHEET\n");
                printf("------------------------------------------------------------------------------------------\n");
                printf("\nEnter the S.no. of the scoresheet to be viewed:\n\n");          //  
                printf("S.no.   MATCH NAME      DATE \n");                                //   displaying all the created scoresheets.
                for(l=0;l<=i;l++)                                                         //    
                    printf("%d.      %s         %s \n",l+1,a[l].name,a[l].date);          //           
                a:
                scanf("%d",&g); 
                if(g>i+1 || g<=0)
                { printf("Please enter valid input: "); goto a; }                                                                       
                ssn=g-1;
                view(ssn);                                                   // caling the view() function for the entered scoresheet index (ssn).
                printf("View another scoresheet? [1]yes [0]no ");
                scanf("%d",&z);
              }while(z==1);                                                  // do while loop allows to view another scoresheet.
            }
          break;
      case 3:                                                                // case for editing scoresheet.
          if(strlen(a[0].name)==0)
              printf("\nPlease create scoresheet first.\n\n");               // error message is displayed if no scoresheet is created.
          else
            {    
              do
                {   
                  printf("\n------------------------------------------------------------------------------------------\n");
                  printf("                                   EDIT SCORESHEET\n");
                  printf("------------------------------------------------------------------------------------------\n\n");
                  printf("Enter the S.no. of the scoresheet to be edited:\n\n");       //  
                  printf("S.no.   MATCH NAME      DATE \n");                           //  displaying all the created scoresheets.
                  for(l=0;l<=i;l++)                                                    //    
                      printf("%d.      %s         %s \n",l+1,a[l].name,a[l].date);     //    
                  b:
                  scanf("%d",&g);                                                      //  user inputs the scoresheet they chose to edit.
                  if(g>i+1 || g<=0)
                  { printf("Please enter valid input: "); goto b; }                                                               
                  ssn=g-1;
                  printf("\n------------------------------------------------------------------------------------------\n");
                  edit(ssn);                                                         // calling the edit() function for the selected scoresheet index.
                  printf("\nThe scoresheet after the changes made: \n");
                  view(ssn);                                                         // calling the view() function to display the edited scoresheet. 
                  printf("Do you want to edit another scoresheet? [1]yes [0]no ");
                  scanf("%d",&z);                                                    
                }while(z==1);                                                        // do while loop allows to edit another scoresheet.  
            }
          break;
      case 4:                                                                        // case to exit the main menu and terminate the program.
          z=0;
          goto e;
      default:                                                           //  error message is shown when user inputs opion not available in main menu.
          printf("Please enter a valid option. "); goto c;
    }
    printf("\nReturn to main menu? [1]yes [0]no ");                      // after a case breaks, user can enter the main menu by entering 1.                         
    scanf("%d",&z);
    if(z!=1)
    { e:
      printf("\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
      printf("                  THANK YOU FOR USING THE CRICKET SCORESHEET CREATOR :)                   \n");
      printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    }
  }while(z==1);
  return 0;
}


int new()                                // function to create new scoresheet. Returns the total mumber of scoresheets created (int i).
{   
  int z,i=0,m,n=1,k=0;
  char choice;
  do 
  { printf("\n------------------------------------------------------------------------------------------\n");
    printf("                                    NEW SCORESHEET\n");
    printf("------------------------------------------------------------------------------------------\n\n");
    printf("Enter match name: ");              scanf("%s",a[i].name);                        //   
    printf("Enter match venue: ");             scanf("%s",a[i].venue);                       //   > i- maintains the indexing of the 
    printf("Enter match date:[DD-MM-YYYY] ");  scanf("%s",a[i].date);                        //     aray of structure a[100].
    printf("Enter match time: ");              scanf("%s",a[i].time);                        //                          
    printf("Enter team 1 name: ");             scanf("%s",a[i].tname1);                      //   > getting the general informaion 
    printf("Enter team 2 name: ");             scanf("%s",a[i].tname2);                      //     about the cricket match
    printf("Enter toss winner: ");             scanf("%s",a[i].tossw);                       //     from the user.
    printf("Enter toss winner choice (Bat/Bowl): ");      scanf("%s",a[i].twc);              //  
    printf("\n------------------------------------------------------------------------------------------\n\n");
    printf("Innings 1 details:\n\n");                                                        // The details of Innings 1 are collected.
    printf("Batting team details:\n");
    printf("[after entering balls faced, enter 1 to add another batsmen or enter 0 to exit]\n");
    k=0;
    do 
    {
      printf("\nEnter batsman %d name: ",k+1); scanf ("%s",t1[i][k].batname);                //   details of diffrent batsman of TEAM 1
      printf("Enter runs scored: ");           scanf("%d",&t1[i][k].batruns);                //   are collected in this do while loop.                              
      printf("Enter balls faced: ");           scanf("%d",&t1[i][k].batballs);               //   i - index of the match (0-99)                                                
      scanf("%d",&m);                                                                        //   k - index of the batsman (0-10)               
      if (m==1)
      k+=1;
      if (k>11)                                                                              //  limits the no. of batsmen to 11.
      m=0;
    }while(m==1);
    printf("\nBowling team details:\n");
    printf("[after entering wickets taken, enter 1 to add another bowler or enter 0 to exit]\n");
    k=0;
    do 
    {
      printf("\nEnter bowler %d name: ",k+1);  scanf ("%s",t2[i][k].bowlname);               //   details of diffrent bowlers of TEAM 2 
      printf("Enter runs conceded: ");         scanf("%d",&t2[i][k].bowlruns);               //   are collected in this do wjile loop.
      printf("Enter overs bowled: ");          scanf("%f",&t2[i][k].overs);                  //   
      printf("Enter extras conceded: ");       scanf("%d",&t2[i][k].extras);                 //   i - index of the match (0-99)
      printf("Enter wickets taken: ");         scanf("%d",&t2[i][k].wickets);                //   k - index of the bowler (0-10)
      scanf("%d",&m);
      if (m==1)
      k+=1;
      if (k>11)
      m=0;            
    }while(m==1);
    printf("\n------------------------------------------------------------------------------------------\n\n");
    printf("Innings 2 details:\n\n");                                                       // 2nd Innings details are collected.
    printf("Batting team details:\n");
    printf("[after entering balls faced, enter 1 to add another batsmen or enter 0 to exit]\n");
    k=0;
    do 
    {
      printf("\nEnter batsman %d name: ",k+1); scanf ("%s",t2[i][k].batname);             //   details of diffrent batsmen of TEAM 2 
      printf("Enter runs scored: ");           scanf("%d",&t2[i][k].batruns);             //   are collected in this do while loop.
      printf("Enter balls faced: ");           scanf("%d",&t2[i][k].batballs);
      scanf("%d",&m);
      if (m==1)
      k+=1;
      if (k>11)
      m=0;
    }while(m==1);
    printf("\nBowling team details:\n");
    printf("[after entering wickets taken, enter 1 to add another bowler or enter 0 to exit]\n");
    k=0;
    do 
    {
      printf("\nEnter bowler %d name: ",k+1);  scanf ("%s",t1[i][k].bowlname);         //   details of diffrent bowlers of TEAM 1
      printf("Enter runs conceded: ");         scanf("%d",&t1[i][k].bowlruns);         //   are collected in this do wjile loop.
      printf("Enter overs bowled: ");          scanf("%f",&t1[i][k].overs); 
      printf("Enter extras conceded: ");       scanf("%d",&t1[i][k].extras);
      printf("Enter wickets taken: ");         scanf("%d",&t1[i][k].wickets);
      scanf("%d",&m);
      if (m==1)
      k+=1;
      if (k>11)                                                               
      m=0;
    }while(m==1);
    printf("\n------------------------------------------------------------------------------------------\n\n");
    printf("Enter the winning team's name: "); scanf("%s",a[i].wname);                                          // name of the winning team is collected.
    printf("\n------------------------------------------------------------------------------------------\n\n");
    d:
    printf("Enter [e] to edit or [c] to continue "); scanf("%s",&choice);            // by entering e, user can edit the created scoresheet.
    if (choice=='e')                                                
    edit(i);                                                          // when e is entered, edit() function is called for that scoresheet.
    else if(choice!='c') 
    goto d;
    printf("\nDo you want to create another scoresheet? [1]yes [0]no "); scanf("%d",&z);
    if(z==1)
      i+=1;
  }while(z==1);
  return i;
}

void view(int ssn)                      // function to view the created scoresheets.   
{                                       // int ssn (index of the scoresheet to be viewed) is passed in the function.
  int l;
  printf("\n------------------------------------------------------------------------------------------\n");
  printf("                                 MATCH - %s\n",a[ssn].name);
  printf("------------------------------------------------------------------------------------------\n\n");
  printf("Match name: %s \n",a[ssn].name);                                            // 
  printf("Match venue: %s \n",a[ssn].venue);                                          //
  printf("Date: %s \n",a[ssn].date);                                                  //  prints all the general informaion
  printf("Time: %s \n",a[ssn].time);                                                  //      of the match of index ssn.
  printf("Match between \"%s\" and \"%s\" \n",a[ssn].tname1,a[ssn].tname2);           //
  printf("\"%s\" won the toss and chose to \"%s\" \n\n",a[ssn].tossw,a[ssn].twc);     //
  printf("------------------------------------------------------------------------------------------\n\n");
  printf("Innings 1:\n\n");                                                   // details of 1St innnings is printed.
  printf("Batting details:\n\n");
  printf("S.no.     NAME     RUNS     BALLS    STRIKE RATE\n"); 
  l=0;
  for(l=0;l<=10;l++)
  {
    if(strlen(t1[ssn][l].batname)==0)                                         // TEAM 1 batting details are displayed.
    break;
    else
    {
      t1[ssn][l].strike= ((float)t1[ssn][l].batruns/t1[ssn][l].batballs)*100;     // strike rate of the batsman is calculated.
      printf("%d        %s     %d       %d       %.2f\n",l+1,t1[ssn][l].batname,t1[ssn][l].batruns,t1[ssn][l].batballs,t1[ssn][l].strike);
      a[ssn].tscore1=a[ssn].tscore1+t1[ssn][l].batruns;                           // the runs scored by each batsman is added to the total TEAM 1 score.
    }
  }
  printf("\nBowling details:\n\n");
  printf("S.no.      NAME      OVERS     WICKETS   EXTRAS   ECONOMY\n");
  l=0;
  for(l=0;l<=10;l++)
  {
    if(strlen(t2[ssn][l].bowlname)==0)                                    // TEAM 2 bowling details are displayed.
    break;
    else
    { 
      a[ssn].twickets2=a[ssn].twickets2+t2[ssn][l].wickets;               // wickets taken by each bowler is added to the total TEAM 2 wickets. 
      t2[ssn][l].eco= (t2[ssn][l].bowlruns+t2[ssn][l].extras/t2[ssn][l].overs);             // economy of each bowler is calculated.
      printf("%d         %s      %.1f         %d        %d       %.2f \n",l+1,t2[ssn][l].bowlname,t2[ssn][l].overs,t2[ssn][l].wickets,t2[ssn][l].extras,t2[ssn][l].eco);
      a[ssn].tscore1=a[ssn].tscore1+t2[ssn][l].extras;                    // extras conceded by each bowler is added to the total TEAM 1 score.
    }
  }
  printf("\n1st Innings score: %d/%d \n\n",a[ssn].tscore1,a[ssn].twickets2);     // TEAM 1 total score and TEAM 2 total wickets are displayed.
  printf("------------------------------------------------------------------------------------------\n\n");
  printf("Innings 2:\n\n");                                               // details of 1St innnings is printed.
  printf("Batting details:\n\n");
  printf("S.no.     NAME     RUNS     BALLS    STRIKE RATE\n");
  l=0;
  for(l=0;l<=11;l++)
  {
    if(strlen(t2[ssn][l].batname)==0)                                   // TEAM 2 batting details are displayed.
    break;
    else
    {
      t2[ssn][l].strike= ((float)t2[ssn][l].batruns/t2[ssn][l].batballs)*100;
      printf("%d        %s     %d       %d       %.2f \n",l+1,t2[ssn][l].batname,t2[ssn][l].batruns,t2[ssn][l].batballs,t2[ssn][l].strike);
      a[ssn].tscore2=a[ssn].tscore2+t2[ssn][l].batruns;
    }
  }
  printf("\nBowling details:\n\n");
  printf("S.no.      NAME      OVERS     WICKETS   EXTRAS   ECONOMY\n");
  l=0;
  for(l=0;l<=11;l++)
  {
    if(strlen(t1[ssn][l].bowlname)==0)                                  // TEAM 1 bowling details are displayed.
    break;
    else
    {
      a[ssn].twickets1=a[ssn].twickets1+t1[ssn][l].wickets;
      t1[ssn][l].eco= (t1[ssn][l].bowlruns+t2[ssn][l].extras/t1[ssn][l].overs);
      printf("%d         %s      %.1f         %d        %d       %.2f \n",l+1,t1[ssn][l].bowlname,t1[ssn][l].overs,t1[ssn][l].wickets,t1[ssn][l].extras,t1[ssn][l].eco);
      a[ssn].tscore2=a[ssn].tscore2+t1[ssn][l].extras;
    }
  }
  printf("\n2nd Innings score: %d/%d \n\n",a[ssn].tscore2,a[ssn].twickets1);    // TEAM 2 total score and TEAM 1 total wickets are displayed.
  printf("------------------------------------------------------------------------------------------\n\n");
  printf("Match won by \"%s\"\n\n",a[ssn].wname);                                         // match winner name is displayed.
  printf("------------------------------------------------------------------------------------------\n\n");
}

void edit(int ssn)           // function to edit created scoresheet. 
{                            // int ssn (index of the scoresheet to be edited) is passed in the function. 
  int g,s,l,w,z;
  do
  {   
    printf("\nENTER THE S.NO. OF THE DETAIL TO BE EDITED:\n\n");                // details of that match are briefly displayed.
    printf("1. Match name: %s \n",a[ssn].name);                                 // user is asked to choose the detail that has to edited.
    printf("2. Match venue: %s \n",a[ssn].venue); 
    printf("3. Date: %s \n",a[ssn].date);
    printf("4. Match time: %s \n",a[ssn].time);
    printf("5. Match between \"%s\" and \"%s\" \n",a[ssn].tname1,a[ssn].tname2);
    printf("6. \"%s\" won the toss and chose to \"%s\" \n",a[ssn].tossw,a[ssn].twc);
    printf("7. 1st Innings details\n");
    printf("8. 2nd Innings details\n");
    printf("9. Match won by \"%s\"\n",a[ssn].wname);
    f:
    scanf("%d",&g);
    switch(g)                                                                     
    {                                                                            // cases 1-6 and case 9 allows user to edit the general 
      case 1:                                                                    // informaion of that match.
          printf("\nEnter new match name: "); scanf("%s",a[ssn].name);
          break;
      case 2:
          printf("\nEnter new match venue: "); scanf("%s",a[ssn].venue);
          break;
      case 3:
          printf("\nEnter new match date:[DD-MM-YYYY] "); scanf("%s",a[ssn].date);
          break;
      case 4:
          printf("\nEnter new match time: "); scanf("%s",a[ssn].time);
          break;
      case 5:
          printf("\nEnter new team 1 name: "); scanf("%s",a[ssn].tname1);
          printf("Enter new team 2 name: "); scanf("%s",a[ssn].tname2);
          break;
      case 6:
          printf("\nEnter new toss winner: "); scanf("%s",a[ssn].tossw);
          printf("Enter new toss winner choice (Bat/Bowl): "); scanf("%s",a[ssn].twc);
          break;
      case 7:                                                              // case 7 allows the user to edit the details of 1st innings.
          printf("\nEnter the S.no. of the 1st Innings detail to be edited: \n");
          printf("[Note that the S.nos. are continous.] \n\n");
          printf("Batting details:\n\n");
          printf("S.no.     NAME     RUNS     BALLS\n");                 // batsmen and bowlers details of 1st innings are displayed in continous serial numbers.
          l=0;
          for(l=0;l<=11;l++)
            if(strlen(t1[ssn][l].batname)==0)
             break;
            else
            printf("%d        %s     %d       %d\n",l+1,t1[ssn][l].batname,t1[ssn][l].batruns,t1[ssn][l].batballs);
          printf("\nBowling details:\n\n");
          printf("S.no.      NAME      OVERS     WICKETS   EXTRAS\n");
          w=l; l=0;
          for(l=0;l<=11;l++)
           if(strlen(t2[ssn][l].bowlname)==0)
            break;
           else
            printf("%d         %s      %.1f         %d        %d\n",w+l+1,t2[ssn][l].bowlname,t2[ssn][l].overs,t2[ssn][l].wickets,t2[ssn][l].extras);   
          scanf("%d",&s);                                                // the user can enter the serial number of the detial that has to be edited.
          if(s<=w)
          {
            a[ssn].tscore1=0;
            printf("\nEnter new batsman %d name: ",s);                   // the details of the choosen batsmen is re-entered. 
            scanf ("%s",t1[ssn][s-1].batname);
            printf("Enter runs scored: ");
            scanf("%d",&t1[ssn][s-1].batruns);
            printf("Enter balls faced: ");
            scanf("%d",&t1[ssn][s-1].batballs);
          }
          else
          {
            a[ssn].tscore1=0;
            a[ssn].twickets2=0;                                          // the detail of the choosen bowler is re-entered.
            printf("\nEnter new bowler %d name: ",s-w);
            scanf ("%s",t2[ssn][s-w-1].bowlname);
            printf("Enter runs conceded: ");
            scanf("%d",&t2[ssn][s-w-1].bowlruns);
            printf("Enter overs bowled: ");
            scanf("%f",&t2[ssn][s-w-1].overs);
            printf("Enter extras conceded: ");
            scanf("%d",&t2[ssn][s-w-1].extras);
            printf("Enter wickets taken: ");
            scanf("%d",&t2[ssn][s-w-1].wickets);
          }
          break;
      case 8:                                                                       // case 8 allows the user to edit the details of 2nd innings.
          printf("\nEnter the S.no. of the 2nd Innings detail to be edited: \n");
          printf("[Note that the S.nos. are continous.] \n\n");
          printf("Batting details:\n\n");
          printf("S.no.     NAME     RUNS     BALLS\n");
          l=0;
          for(l=0;l<=11;l++)
           if(strlen(t2[ssn][l].batname)==0)
           break;
           else
            printf("%d        %s     %d       %d\n",l+1,t2[ssn][l].batname,t2[ssn][l].batruns,t2[ssn][l].batballs);
          printf("\nBowling details:\n\n");
          printf("S.no.      NAME      OVERS     WICKETS   EXTRAS\n");
          w=l; l=0;
          for(l=0;l<=11;l++)
           if(strlen(t1[ssn][l].bowlname)==0)
           break;
           else
            printf("%d         %s      %.1f         %d        %d\n",w+l+1,t1[ssn][l].bowlname,t1[ssn][l].overs,t1[ssn][l].wickets,t1[ssn][l].extras);
          scanf("%d",&s);
          if(s<=w)
          {
            a[ssn].tscore2=0;
            printf("\nEnter new batsman %d name: ",s);
            scanf ("%s",t2[ssn][s-1].batname);
            printf("Enter runs scored: ");
            scanf("%d",&t2[ssn][s-1].batruns);
            printf("Enter balls faced: ");
            scanf("%d",&t2[ssn][s-1].batballs);
          }
          else
          {
            a[ssn].tscore2=0;
            a[ssn].twickets1=0;
            printf("\nEnter new bowler %d name: ",s-w);
            scanf ("%s",t1[ssn][s-w-1].bowlname);
            printf("Enter runs conceded: ");
            scanf("%d",&t1[ssn][s-w-1].bowlruns);
            printf("Enter overs bowled: ");
            scanf("%f",&t1[ssn][s-w-1].overs);
            printf("Enter extras conceded: ");
            scanf("%d",&t1[ssn][s-w-1].extras);
            printf("Enter wickets taken: ");
            scanf("%d",&t1[ssn][s-w-1].wickets);
          }
          break;
      case 9:
          printf("\nEnter the new winning team's name: ");
          scanf("%s",a[ssn].wname);
          break;
      default:
          printf("Please enter a vaild choice. ");
          goto f;
    }
    printf("\nEdit another detail in the same match? [1]yes [0]no ");
    scanf("%d",&z);
  }while(z==1);
}
