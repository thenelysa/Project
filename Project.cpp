#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct membership_time
  {
  	int year,month,day;
  };
struct time
  {
  	int shour,smin,ehour,emin;
  };   
struct member_info
  {
  	char name[25];
  	int id,age,height,weight,choicemembership;
  	struct membership_time time;
  	char workchoice[10];
  	struct time tm;
  }; 
struct trainer_info
  {
  	char name[25];
  	int id,age,salary,stime,etime;
  };   
struct equipment_info
  {
  	char equip[30];
  	int numbers;
  };
struct workout_info
  {
  	char workout_focus[10];
  	int wtime;
  };
struct workout_infoA
  {
  	int wid;
  	struct workout_info wi[6];
  };
void menu();      
int main()
   {
   	  int choice,choicemembership;
	  long int recsize,recsize2,recsize3,recsize4,tempsize1;  	
   	  FILE *fp1,*fp2,*fp3,*fp4,*ft1,*ft2,*ft3,*ft4;
   	  struct member_info dataM;
   	  struct trainer_info dataT;
   	  struct equipment_info dataE;
   	  struct workout_infoA dataW;
   	  //File opening process
   	  fp1=fopen("E:\\BITproject.txt","rb+");
   	  if(fp1==NULL)
   	     {
   	     	fp1=fopen("E:\\BITproject.txt","wb+");
   	     	if(fp1==NULL)
   	     	{
   	     	    printf("File not opened!!!");
   	     	    exit(0);
   	     	    return 0;
   	        }
	   	 }
	  fp2=fopen("E:\\TrainerInfo.txt","rb+");
	  if(fp2==NULL)
	     {
	     	fp2=fopen("E:\\TrainerInfo.txt","wb+");
   	     	if(fp1==NULL)
   	     	 {
   	     	 	printf("File2 not opened!!!");
	     	    exit(0);
   	     	    return 0;
			 }
	     } 	
	  fp3=fopen("E:\\EquipmentInfo.txt","rb+");
	  if(fp3==NULL)
	     {
	     	fp3=fopen("E:\\EquipmentInfo.txt","wb+");
	        if(fp3==NULL)
	         {
	     	   printf("File3 not opened!!!");
	     	   exit(0);
   	     	   return 0;
	         }
	     }
	  fp4=fopen("E:\\WorkoutInfo.txt","rb+");
	  if(fp4==NULL)
	     {
	     	fp4=fopen("E:\\WorkoutInfo.txt","wb+");
	        if(fp4==NULL)
	         {
	     	   printf("File4 not opened!!!");
	     	   exit(0);
   	     	    return 0;
	         }
	     }       
	  recsize=sizeof(dataM); 
	  recsize2=sizeof(dataT);
	  recsize3=sizeof(dataE);
	  recsize4=sizeof(dataW); 
	  tempsize1=sizeof(dataE.numbers);
	  while(1)
	   { 
	    top:
	    menu();
	    printf("\n\n\n\n");   
   	  	printf("\n\t\t\t\t\t\t\t\t\t(|--|)Gym Managemnet(|--|)");
   	  	printf("\n\t\t\t\t\t\t\t\t\t**************************");
   	  	printf("\n");
   	  	printf("\n\t\t\t\t\t\t\t\t\t1.Add Members");
   	  	printf("\n\t\t\t\t\t\t\t\t\t2.List Members");
   	  	printf("\n\t\t\t\t\t\t\t\t\t3.Find Members");
   	  	printf("\n\t\t\t\t\t\t\t\t\t4.Workout Sheet");
   	  	printf("\n\t\t\t\t\t\t\t\t\t5.Trainer Information");
   	  	printf("\n\t\t\t\t\t\t\t\t\t6.Equipement Information");
   	  	printf("\n\t\t\t\t\t\t\t\t\t7.Exit");
   	  	printf("\n");
   	  	flag:
   	  	printf("\n\t\t\t\t\t\t\t\t\tPlaease enter your choice down bellow");
   	  	printf("\n\t\t\t\t\t\t\t\t\t\t\tChoice:");
   	  	scanf("%d",&choice);
   	  	fflush(stdin);
   	  	system("cls");
   	    switch(choice)
   	      {
   	    	case 1://Adding a member
   	    	 {	
			   add: 	
			   printf("\n\n\n\n\n\n\n\n"); 
   	    	   printf("\n\t\t\t\t\t\t\t\t\t(|--|)Add Member details down bellow(|--|)");
   	    	   printf("\n\t\t\t\t\t\t\t\t\t******************************************");
			   printf("\n");
			   printf("\n\t\t\t\t\t\t\t\t\tName:");
			   gets(dataM.name);
			   fflush(stdin);
			   printf("\t\t\t\t\t\t\t\t\tId:");
			   scanf("%d",&dataM.id);
			   fflush(stdin); 
			   printf("\t\t\t\t\t\t\t\t\tAge:");
			   scanf("%d",&dataM.age);
			   fflush(stdin);
			   printf("\t\t\t\t\t\t\t\t\tHeight(in foot):");
			   scanf("%d",&dataM.height);
			   fflush(stdin);
			   printf("\t\t\t\t\t\t\t\t\tWeight(in kg):");
			   scanf("%d",&dataM.weight);
			   fflush(stdin);
			   printf("\t\t\t\t\t\t\t\t\tMembership starting date:");
			   printf("\n\t\t\t\t\t\t\t\t\tYear:");
			   scanf("%d",&dataM.time.year);
			   fflush(stdin);
			   monthwrong:
			   printf("\t\t\t\t\t\t\t\t\tMonth:");
			   scanf("%d",&dataM.time.month);
			   fflush(stdin);
			   if(dataM.time.month>12||dataM.time.month<1)
			     {
			     	printf("Wrong Entry!!!!");
			     	printf("\n");
			     	goto monthwrong;
				 }	 
			   daywrong: 
			   printf("\t\t\t\t\t\t\t\t\tDay:");
			   scanf("%d",&dataM.time.day);
			   fflush(stdin);
			   if(dataM.time.day>31||dataM.time.day<1)
			     {
			     	printf("Wrong Entry!!");
			     	printf("\n");
			     	goto daywrong;
			     }
			   membershipwrong:	  
			   printf("\t\t\t\t\t\t\t\t\tChoose a membership plan:");
			   printf("\n\t\t\t\t\t\t\t\t\t3months");
			   printf("\n\t\t\t\t\t\t\t\t\t6months");
			   printf("\n\t\t\t\t\t\t\t\t\t9months");
			   printf("\n\t\t\t\t\t\t\t\t\t12months");
			   printf("\n\t\t\t\t\t\t\t\t\tEnter the membership plan(months):");
			   scanf("%d",&dataM.choicemembership);
			   if(dataM.choicemembership==3||dataM.choicemembership==6||dataM.choicemembership==9||dataM.choicemembership==12)
			   { 
			      int eyear,emonth,tempmonth;
			      tempmonth=dataM.time.month+dataM.choicemembership;
	              printf("\n\t\t\t\t\t\t\t\t\tYour package will end after %dmonths prior to this date.",dataM.choicemembership);
	              if(tempmonth>12)
	                 {
	                 	eyear=dataM.time.year+1;
	                 	emonth=tempmonth-12;
	                 	printf("\n\t\t\t\t\t\t\t\t\tMembership Ending Date:");
	                 	printf("\n\t\t\t\t\t\t\t\t\tYear:%d",eyear);
	                 	printf("\n\t\t\t\t\t\t\t\t\tMonth:%d",emonth);
	                 	printf("\n\t\t\t\t\t\t\t\t\tDay:%d",dataM.time.day);
					 }
			      else
				     {
				     	printf("\n\t\t\t\t\t\t\t\t\tMembership Ending Date:");
	                 	printf("\n\t\t\t\t\t\t\t\t\tYear:%d",dataM.time.year);
	                 	printf("\n\t\t\t\t\t\t\t\t\tMonth:%d",dataM.time.month+dataM.choicemembership);
	                 	printf("\n\t\t\t\t\t\t\t\t\tDay:%d",dataM.time.day);
				     }		 
			   }
			   else
			   {
			   	 printf("\n\t\t\t\t\t\t\t\t\tThis package doesnot exist!!");
			   	 goto membershipwrong;
			   }
			   fwrite(&dataM,recsize,1,fp1);
			   char YNmember;
			   YNwrong:
			   printf("\n\t\t\t\t\t\t\t\t\tDo you want to add another member(input Y/N):");
			   scanf("%s",&YNmember);
			   fflush(stdin);
			   system("cls");
			   if(YNmember=='Y'||YNmember=='y')
			     {
			     	goto add;
				 }
			   else if(YNmember=='N'||YNmember=='n')
			      {
			      	break;
			      }
				else
				  {
				  	 printf("\n\t\t\t\t\t\t\t\t\tWrong Entry!!");
				  	 goto YNwrong;
				  }
			   printf("\n\t\t\t\t\t\t\t\t\tPress any key to continue");
			   getchar();
			   system("cls");  			  	        
   	    	   break;
   	         }
   	    	case 2://Listing all the members
   	    	 {
   	    	   int anynumber;
   	    	   printf("\n");
   	    	   printf("\n\t\t\t\t\t\t\t\t\tList of all members:");
   	    	   printf("\n");
   	    	   rewind (fp1);
	           while(fread(&dataM,recsize,1,fp1)>0)
		     {

	                 printf("\n");
	                 printf("\n\t\t\t\t\t\t\t\t\tName:");
	                 puts(dataM.name);
	                 printf("\t\t\t\t\t\t\t\t\tId:%d",dataM.id);
			         printf("\n\t\t\t\t\t\t\t\t\tAge:%d",dataM.age);
			         printf("\n\t\t\t\t\t\t\t\t\tHeight(in foot):%d",dataM.height);
			         printf("\n\t\t\t\t\t\t\t\t\tWeight(in kg:)%d",dataM.weight);
			         printf("\n\t\t\t\t\t\t\t\t\tMembership starting date:");
			         printf("\n\t\t\t\t\t\t\t\t\tYear:%d",dataM.time.year);
			         printf("\n\t\t\t\t\t\t\t\t\tMonth:%d",dataM.time.month);
			         printf("\n\t\t\t\t\t\t\t\t\tDay:%d",dataM.time.day); 
	                 printf("\n\t\t\t\t\t\t\t\t\tYour package will end after %dmonths prior to this date.",dataM.choicemembership);
					 int eyear1,emonth1,tempmonth1;
			         tempmonth1=dataM.time.month+dataM.choicemembership;
	                 if(tempmonth1>12)
	                  {
	                 	eyear1=dataM.time.year+1;
	                 	emonth1=tempmonth1-12;
	                 	printf("\n\t\t\t\t\t\t\t\t\tMembership Ending Date:");
	                 	printf("\n\t\t\t\t\t\t\t\t\tYear:%d",eyear1);
	                 	printf("\n\t\t\t\t\t\t\t\t\tMonth:%d",emonth1);
	                 	printf("\n\t\t\t\t\t\t\t\t\tDay:%d",dataM.time.day);
					  }
			         else
				      {
				     	printf("\n\t\t\t\t\t\t\t\t\tMembership Ending Date:");
	                 	printf("\n\t\t\t\t\t\t\t\t\tYear:%d",dataM.time.year);
	                 	printf("\n\t\t\t\t\t\t\t\t\tMonth:%d",dataM.time.month+dataM.choicemembership);
	                 	printf("\n\t\t\t\t\t\t\t\t\tDay:%d",dataM.time.day);
				      }		          
	             } 
			   printf("\n\t\t\t\t\t\t\t\t\tPress any key to continue.");  
	           getchar();
			   system("cls"); 
			   break;
		     }
			case 3://Finding a gym member to either show,modify or delete the data
			 {	
			   char member_name[20],membermodify;
			   int member_id,count=0;
			   printf("\n");
			   refind:
			   menu();	
			   printf("\n\n");	
			   printf("\n\t\t\t\t\t\t\t\t\t(|--|)Enter Name and ID down bellow(|--|)");
			   printf("\n\t\t\t\t\t\t\t\t\t*****************************************");
			   printf("\n\t\t\t\t\t\t\t\t\tName:");
			   gets(member_name);
			   fflush(stdin);
			   printf("\t\t\t\t\t\t\t\t\tID:");
			   scanf("%d",&member_id);
			   fflush(stdin);
			   rewind(fp1);
			   while(fread(&dataM,recsize,1,fp1)>0)
                {
   		          if(strcmp(dataM.name,member_name)==0&&dataM.id==member_id)
                    {
                    	count=count+1;
                    }
                }
               if(count==0)
			     {
			     	printf("\n\t\t\t\t\t\t\t\t\tMember not found.");
			     	goto refind;
				  } 
			   int datachoice;
			   printf("\n\t\t\t\t\t\t\t\t\tWhat do you want to do with this data:");
			   datachoicewrong:
			   printf("\n\t\t\t\t\t\t\t\t\t1.Show");
	           printf("\n\t\t\t\t\t\t\t\t\t2.Modify");
			   printf("\n\t\t\t\t\t\t\t\t\t3.Delete");
		       printf("\n\t\t\t\t\t\t\t\t\t4.Exit");
	           printf("\n\t\t\t\t\t\t\t\t\tInput your choice:");
	           scanf("%d",&datachoice);
		       fflush(stdin);
		       system("cls"); 
		       switch(datachoice)
			       {
			       	  case 1://Showing the whole data based on the name and id given
			       	  	{
			       	  		rewind(fp1);
			       	  		while(fread(&dataM,recsize,1,fp1)>0)
	                           { 
	                             if(strcmp(dataM.name,member_name)==0&&dataM.id==member_id)
	                                {
	                                	printf("\n");
	                                    printf("\n\t\t\t\t\t\t\t\t\tName:");
	                                    puts(dataM.name);
	                                    printf("\n\t\t\t\t\t\t\t\t\tId:%d",dataM.id);
			                            printf("\n\t\t\t\t\t\t\t\t\tAge:%d",dataM.age);
			                            printf("\n\t\t\t\t\t\t\t\t\tHeight(in foot):%d",dataM.height);
			                            printf("\n\t\t\t\t\t\t\t\t\tWeight(in kg:)%d",dataM.weight);
			                            printf("\n\t\t\t\t\t\t\t\t\tMembership starting date:");
			                            printf("\n\t\t\t\t\t\t\t\t\tYear:%d",dataM.time.year);
			                            printf("\n\t\t\t\t\t\t\t\t\tMonth:%d",dataM.time.month);
			                            printf("\n\t\t\t\t\t\t\t\t\tDay:%d",dataM.time.day); 
	                                    printf("\n\t\t\t\t\t\t\t\t\tThe package will end after %d months prior to this date.",dataM.choicemembership);  
	                                    int eyear3,emonth3,tempmonth3;
			                            tempmonth3=dataM.time.month+dataM.choicemembership;
	                                    if(tempmonth3>12)
	                                       {
	                 	                      eyear3=dataM.time.year+1;
	                 	                      emonth3=tempmonth3-12;
	                 	                      printf("\n\t\t\t\t\t\t\t\t\tMembership Ending Date:");
	                 	                      printf("\n\t\t\t\t\t\t\t\t\tYear:%d",eyear3);
	                 	                      printf("\n\t\t\t\t\t\t\t\t\tMonth:%d",emonth3);
	                 	                      printf("\n\t\t\t\t\t\t\t\t\tDay:%d",dataM.time.day);
					                       }
			                            else
				                           {
				     	                      printf("\n\t\t\t\t\t\t\t\t\tMembership Ending Date:");
	                 	                      printf("\n\t\t\t\t\t\t\t\t\tYear:%d",dataM.time.year);
	                 	                      printf("\n\t\t\t\t\t\t\t\t\tMonth:%d",dataM.time.month+dataM.choicemembership);
	                 	                      printf("\n\t\t\t\t\t\t\t\t\tDay:%d",dataM.time.day);
				                           }		 
	                                    printf("\n\t\t\t\t\t\t\t\t\tPress any key to continue..");
	                                    getchar();
	                                    system("cls");
								    }
	                           } 
			       	  		break;
					    }
					  case 2://Editing the data 
					    {
					    	rewind(fp1);
			       	  		while(fread(&dataM,recsize,1,fp1)==1)
			       	  		   {
			       	  		   	  if(strcmp(dataM.name,member_name)==0&&dataM.id==member_id)
			       	  		   	    {
			       	  		   	    	 printf("\n\t\t\t\t\t\t\t\t\t(|--|)Modify details down bellow(|--|)");
			                             printf("\n\t\t\t\t\t\t\t\t\t***************************************");
			                             printf("\n\t\t\t\t\t\t\t\t\tName:");
			                             gets(dataM.name);
			                             fflush(stdin);
			                             printf("\t\t\t\t\t\t\t\t\tId:");
			                             scanf("%d",&dataM.id);
			                             fflush(stdin); 
			                             printf("\t\t\t\t\t\t\t\t\tAge:");
			                             scanf("%d",&dataM.age);
			                             fflush(stdin);
			                             printf("\t\t\t\t\t\t\t\t\tHeight(in foot):");
			                             scanf("%d",&dataM.height);
			                             fflush(stdin);
			                             printf("\t\t\t\t\t\t\t\t\tWeight(in kg):");
			                             scanf("%d",&dataM.weight);
			                             fflush(stdin);
			                             printf("\t\t\t\t\t\t\t\t\tMembership starting date:");
			                             printf("\n\t\t\t\t\t\t\t\t\tYear:");
			                             scanf("%d",&dataM.time.year);
			                             fflush(stdin);
			                             monthwrong2:
			                             printf("\t\t\t\t\t\t\t\t\tMonth:");
			                             scanf("%d",&dataM.time.month);
			                             fflush(stdin);
			                             if(dataM.time.month>12||dataM.time.month<1)
			                                {
			     	                            printf("\t\t\t\t\t\t\t\t\tWrong Entry!!!!");
			     	                            printf("\n");
			     	                            goto monthwrong2;
				                            }	 
			                             daywrong2: 
			                             printf("\t\t\t\t\t\t\t\t\tDay:");
			                             scanf("%d",&dataM.time.day);
			                             fflush(stdin);
			                             if(dataM.time.day>31||dataM.time.day<1)
			                                {
			     	                            printf("\n\t\t\t\t\t\t\t\t\tWrong Entry!!");
			     	                            printf("\n");
			     	                            goto daywrong2;
			                                }
			                             membershipwrong2:	  
			                             printf("\n\t\t\t\t\t\t\t\t\tChoose a membership plan:");
			                             printf("\n\t\t\t\t\t\t\t\t\t3months");
			                             printf("\n\t\t\t\t\t\t\t\t\t6months");
			                             printf("\n\t\t\t\t\t\t\t\t\t9months");
			                             printf("\n\t\t\t\t\t\t\t\t\t12months");
			                             printf("\n\t\t\t\t\t\t\t\t\tEnter the membership plan(months):");
			                             scanf("%d",&dataM.choicemembership);
			                             if(dataM.choicemembership==3||dataM.choicemembership==6||dataM.choicemembership==9||dataM.choicemembership==12)
			                                {  
	                                            printf("\n\t\t\t\t\t\t\t\t\tYour package will end after %dmonths prior to this date.",dataM.choicemembership);
	                                            int eyear2,emonth2,tempmonth2;
			                                    tempmonth2=dataM.time.month+dataM.choicemembership;
	                                            if(tempmonth2>12)
	                                              {
	                 	                             eyear2=dataM.time.year+1;
	                 	                             emonth2=tempmonth2-12;
	                 	                             printf("\n\t\t\t\t\t\t\t\t\tMembership Ending Date:");
	                 	                             printf("\n\t\t\t\t\t\t\t\t\tYear:%d",eyear2);
	                 	                             printf("\n\t\t\t\t\t\t\t\t\tMonth:%d",emonth2);
	                 	                             printf("\n\t\t\t\t\t\t\t\t\tDay:%d",dataM.time.day);
					                              }
			                                    else
				                                  {
				     	                             printf("\n\t\t\t\t\t\t\t\t\tMembership Ending Date:");
	                 	                             printf("\n\t\t\t\t\t\t\t\t\tYear:%d",dataM.time.year);
	                 	                             printf("\n\t\t\t\t\t\t\t\t\tMonth:%d",dataM.time.month+dataM.choicemembership);
	                 	                             printf("\n\t\t\t\t\t\t\t\t\tDay:%d",dataM.time.day);
				                                  }		 
			                                }
			                             else
			                                {
			   	                                printf("\n\t\t\t\t\t\t\t\t\tThis package doesnot exist!!");
			   	                                goto membershipwrong;
			                                }
			                             fseek(fp1,-recsize,SEEK_CUR);  
			                             fwrite(&dataM,recsize,1,fp1);
			                             printf("\n\t\t\t\t\t\t\t\t\tPress any key to continue..");
	                                     getchar();
			                             system("cls");
			                             break;
									}
							   }
					    	break;
					    }
					  case 3://Deleting the data
					    {
			   	   	        ft1=fopen("E:\\temp1.txt","wb+");
			                if(ft1==NULL)
			                    {
			                	     printf("\n\t\t\t\t\t\t\t\t\tTemp1 File not opened!!");
						             exit(0);
   	     	                         return 0;
		      	               }
					    	rewind(fp1);
			       	  		while(fread(&dataM,recsize,1,fp1)==1)
			       	  		   {
			       	  		   	  if(strcmp(dataM.name,member_name)!=0&&dataM.id!=member_id)
									 {
							    	  	fwrite(&dataM,recsize,1,ft1);
								     }   
							    }
							fclose(fp1);    
						    fclose(ft1);
				  		    remove("E:\\BITproject.txt");
				 		    rename("E:\\temp1.txt","E:\\BITproject.txt");  
						    fp1=fopen("E:\\BITproject.txt","rb+");
	                        if(fp1==NULL)
	                           {
							                printf("\n\t\t\t\t\t\t\t\t\tFile1.1 not opened!!!");
	     	                                exit(0);
   	     	                                return 0;					
	                            }
							ft4=fopen("E:\\Wtemp.txt","wb+");
			                if(ft4==NULL)
			                    {
			                	     printf("\n\t\t\t\t\t\t\t\t\tWtemp File not opened!!");
						             exit(0);
   	     	                         return 0;
		      	               }
					    	rewind(fp4);
			       	  		while(fread(&dataM,recsize,1,fp1)==1)
			       	  		   {
			       	  		   	  if(strcmp(dataM.name,member_name)!=0&&dataM.id!=member_id)
									 {
							    	  	fwrite(&dataM,recsize,1,ft1);
								     }   
							    }
							fclose(fp4);    
						    fclose(ft4);
				  		    remove("E:\\WorkoutInfo.txt");
				 		    rename("E:\\Wtemp.txt","E:\\WorkoutInfo.txt");  
						    fp4=fopen("E:\\WorkoutInfo.txt","rb+");
	                        if(fp4==NULL)
	                           {
							                printf("\n\t\t\t\t\t\t\t\t\tFile4.1 not opened!!!");
	     	                                exit(0);
   	     	                                return 0;					
	                            } 	   	 	   
					    	break;
					    }
					  case 4://Exiting the condition
					    {
					    	printf("\n\t\t\t\t\t\t\t\t\tPress any key to continue..");
							getchar();
							system("cls"); 
					    	break;
					    }
					  default:	
					  printf("\n\t\t\t\t\t\t\t\t\tWrong choice!!");
					  goto datachoicewrong;
					  system("cls");
					  break;				  
				   }
		 	   break;  
			  }	
		    case 4://Finding a workout sheet of a member
		      {
		      	int wcount=0;
		      	char WSname[25];
		      	int i=0;
		      	int WSchoice,WSid;
	 	  	  	NIwrong:
	 	  	  	menu();	
	 	  	  	printf("\n\n");	
		      	printf("\n\t\t\t\t\t\t\t\t\t(|--|)Enter Name and ID(|--|)");
		      	printf("\n\t\t\t\t\t\t\t\t\t*****************************");
		      	printf("\n\t\t\t\t\t\t\t\t\tName:");
	 	  	  	gets(WSname);
		      	fflush(stdin);
		      	printf("\n\t\t\t\t\t\t\t\t\tID:");
		      	scanf("%d",&WSid);
		      	fflush(stdin);
		      	rewind(fp1);
			    while(fread(&dataM,recsize,1,fp1)>0)
			       	{
		      	   	  	if(strcmp(WSname,dataM.name)==0&&WSid==dataM.id)
		      		  	  	  {
		      	 	  	  	  	system("cls");
								wcount=wcount+1;		 	
							  }
					}
				if(wcount==0)
				   {
						printf("\n\t\t\t\t\t\t\t\t\tMember Not Found");
				      	printf("\n\t\t\t\t\t\t\t\t\tPress any key to continue.");
				      	getchar();
				      	system("cls");
					  	goto NIwrong;
				   }
		      	while(1)
		      	 {
		      	 	WSchoicewrong:
		      	 	menu();	
		      	 	printf("\n\n");	
		      	 	printf("\n\t\t\t\t\t\t\t\t\t(|--|)Workout Sheet Info(|--|)");
					printf("\n\t\t\t\t\t\t\t\t\t******************************");   	
		      	 	printf("\n\t\t\t\t\t\t\t\t\t1.Modify Workoutsheet");
		      	 	printf("\n\t\t\t\t\t\t\t\t\t2.Show Workoutsheet");
		      	 	printf("\n\t\t\t\t\t\t\t\t\t3.Exit");
		      	 	printf("\n\t\t\t\t\t\t\t\t\tChoice:");
		      	 	scanf("%d",&WSchoice);
		      	 	fflush(stdin);
		      	 	system("cls");
		      	 	switch(WSchoice)
		      	 	  {
		      	 	  	case 1://Adding Workout information of the member in the workoutsheet
		      	 	  	  {
							WScontinue:
							printf("\n\t\t\t\t\t\t\t\t\tEnter your id:"); 
							scanf("%d",&dataW.wid);
							fflush(stdin);
							printf("\n\t\t\t\t\t\t\t\t\tEnter the workout details of 7days");
							for(i=0;i<7;i++)
							  {
							  	printf("\n\t\t\t\t\t\t\t\t\tWorkout Focus");
							  	printf("\n\t\t\t\t\t\t\t\t\t1.FullBody");
							  	printf("\n\t\t\t\t\t\t\t\t\t2.Arms");
							  	printf("\n\t\t\t\t\t\t\t\t\t3.Abs");
							  	printf("\n\t\t\t\t\t\t\t\t\t4.Legs");
							  	printf("\n\t\t\t\t\t\t\t\t\t5.Rest");
							  	printf("\n\t\t\t\t\t\t\t\t\tFocus(Input in words):");
							  	scanf("%s",&dataW.wi[i].workout_focus);
							  	fflush(stdin);
								printf("\n\t\t\t\t\t\t\t\t\tWorkout Time(hrs spent):");
								scanf("%d",&dataW.wi[i].wtime);
								fflush(stdin);
								system("cls");  
							  }
							fwrite(&dataW,recsize4,1,fp4);     
		      	 	  	  	break;
					      }
					    case 2://Showing the workout sheet of each week
						  {
						  	printf("\n\t\t\t\t\t\t\t\t\tEnter ID:");
						  	scanf("%d",&WSid);
						  	fflush(stdin);
						  	rewind(fp4);
						  	while(fread(&dataW,recsize4,1,fp4)>0)
						  	  {
						  	  	if(WSid==dataW.wid)
						  	  	  {
						  	  	  	printf("\n\t\t\t\t\t\t\t\t\tTrainer ID:%d",dataW.wid);
						  	  	  	printf("\n\t\t\t\t\t\t\t\t\tWorkout Details");
						  	  	  	for(i=0;i<7;i++)
						  	  	  	  {
						  	  	  	    printf("\n\t\t\t\t\t\t\t\t\tWorkout Focus:%s",dataW.wi[i].workout_focus);
						  	  	  	    if(dataW.wi[i].workout_focus=="Rest")
						  	  	  	       {
						  	  	  	       	  break;
											}
						  	  	  	    printf("\n\t\t\t\t\t\t\t\t\tWorkout Time(hrs spent):%d",dataW.wi[i].wtime);
						  	  	      }
								  }
							  }
							printf("\n\t\t\t\t\t\t\t\t\tPress Any Key to Continue...");
							getchar();
							system("cls");  
						  	break;
						  }
						case 3://Exiting to the main menu
						  {
						  	goto top;
							break;
						  }  
						default:  
						printf("\n\t\t\t\t\t\t\t\t\tWrong choice!!");
					    goto WSchoicewrong;
					    system("cls");
					    break;	  
					  }
				 }
			break;
			  }
			case 5://Inputting trainer information 
			 {	
			   int choicetrainer;
			   while(1)
			   {
			   	   Tchoicewrong:
			   	   menu();	
			   	   printf("\n\t\t\t\t\t\t\t\t\t(|--|)Trainer Tnformation(|--|)");
			   	   printf("\n\t\t\t\t\t\t\t\t\t*******************************");
			       printf("\n\t\t\t\t\t\t\t\t\t1.Add Trainer");
			       printf("\n\t\t\t\t\t\t\t\t\t2.Find a Trainer");
			       printf("\n\t\t\t\t\t\t\t\t\t3.List Trainers");
			       printf("\n\t\t\t\t\t\t\t\t\t4.Exit");
			       printf("\n\t\t\t\t\t\t\t\t\tEnter your choice.");
			       scanf("%d",&choicetrainer);
			       fflush(stdin);
			       system("cls");
			       switch(choicetrainer)
			         {
			         	case 1://Adding a new trainer on the gym
			         		{
			         			addtrainer:
			         			printf("\n");
			         			printf("\n\t\t\t\t\t\t\t\t\tEnter Trainer Details:");
			         			printf("\n\t\t\t\t\t\t\t\t\t**********************");
			         			printf("\n\t\t\t\t\t\t\t\t\tName:");
			         			gets(dataT.name);
			         			fflush(stdin);
			         			printf("\t\t\t\t\t\t\t\t\tId:");
			         			scanf("%d",&dataT.id);
			         			fflush(stdin);
			         			printf("\t\t\t\t\t\t\t\t\tAge:");
			         			scanf("%d",&dataT.age);
			         			fflush(stdin);
			         			printf("\t\t\t\t\t\t\t\t\tSalary(Rs.):");
			         			scanf("%d",&dataT.salary);
			         			fflush(stdin);
			         			printf("\t\t\t\t\t\t\t\t\tWorking hours:");
			         			printf("\n\t\t\t\t\t\t\t\t\tStarting time:");
			         			scanf("%d",&dataT.stime);
			         			fflush(stdin);
			         			printf("\t\t\t\t\t\t\t\t\tEnding time:");
			         			scanf("%d",&dataT.etime);
			         			fflush(stdin);
			         			fwrite(&dataT,recsize2,1,fp2);
			         			char YNtrainer;
			                    YNtrainerwrong:
			                    printf("\t\t\t\t\t\t\t\t\tDo you want to add another member(input Y/N):");
			                    scanf("%s",&YNtrainer);
			                    fflush(stdin);
			                    system("cls");
			                    if(YNtrainer=='Y'||YNtrainer=='y')
			                       {
			                        	goto addtrainer;
				                    }
			                    else if(YNtrainer=='N'||YNtrainer=='n')
			                       {
			      	                   break;
					               }
				                else
				                   {
				  	                  printf("\n\t\t\t\t\t\t\t\t\tWrong Entry!!");
				  	                  printf("\n\t\t\t\t\t\t\t\t\tPress any key to continue.");
				  	                  getchar();
				  	                  system("cls");
				  	                  goto YNtrainerwrong;
							       }		
							}
						case 2://Finding and editing the trainer information
							{
								int tcount=0;
								char tname[20];
								int tid;
								invalidtrainer:  
								printf("\n\t\t\t\t\t\t\t\t\tEnter Trainer information");
								printf("\n\t\t\t\t\t\t\t\t\t*************************");
								printf("\n\t\t\t\t\t\t\t\t\tName:");
								gets(tname);
								fflush(stdin);
								printf("\t\t\t\t\t\t\t\t\tID:");
								scanf("%d",&tid);
								fflush(stdin);
								rewind(fp2);
								while(fread(&dataT,recsize2,1,fp2)>0)
								  {
								  	if(strcmp(dataT.name,tname)==0&&tid==dataT.id)
								  	  {
								  	  	printf("\n\t\t\t\t\t\t\t\t\tName:");
			         			        puts(dataT.name);
			         			        printf("\t\t\t\t\t\t\t\t\tId:%d",dataT.id);
			         		   	        printf("\n\t\t\t\t\t\t\t\t\tAge:%d",dataT.age);
			         			        printf("\n\t\t\t\t\t\t\t\t\tSalary(Rs.):%d",dataT.salary);
			         			        printf("\n\t\t\t\t\t\t\t\t\tWorking hours(24hrs format):");
			         	                printf("\n\t\t\t\t\t\t\t\t\tStarting time:%d",dataT.stime);
			         			        printf("\n\t\t\t\t\t\t\t\t\tEnding time:%d",dataT.etime);
			         			        tcount++;
								  	  }
							      }
							    if(tcount==0)
								  {
								  	printf("\n\t\t\t\t\t\t\t\t\tTrainer not found!!");
								  	printf("\n\t\t\t\t\t\t\t\t\tPress any key to continue");
								  	getchar();
								  	system("cls");
								  	goto invalidtrainer;
								  }  
								int tdatachoice;    
							  	printf("\n\t\t\t\t\t\t\t\t\tWhat do you want to do with this data:");
							  	tdatawrong:
								printf("\n\t\t\t\t\t\t\t\t\t1.Modify");
								printf("\n\t\t\t\t\t\t\t\t\t2.Delete");
								printf("\n\t\t\t\t\t\t\t\t\t3.Exit");
								printf("\n\t\t\t\t\t\t\t\t\tEnter your choice:");
								scanf("%d",&tdatachoice);
								fflush(stdin);
								system("cls");
								switch(tdatachoice)
									  {
									  	case 1://Modifying the trainer info
									  		{
									  			rewind(fp2);
								                while(fread(&dataT,recsize2,1,fp2)>0)
								                  {
								                    if(strcmp(dataT.name,tname)==0&&tid==dataT.id)
									  			      {
									  			  	    printf("\n\t\t\t\t\t\t\t\t\tEnter new details:");
									  			  	    printf("\n\t\t\t\t\t\t\t\t\t******************");
									  			  	    printf("\n\t\t\t\t\t\t\t\t\tName:");
			         			                        gets(dataT.name);
			         			                        fflush(stdin);
			         			                        printf("\t\t\t\t\t\t\t\t\tId:");
			         			                        scanf("%d",&dataT.id);
			         			                        fflush(stdin);
			         			                        printf("\t\t\t\t\t\t\t\t\tAge:");
			         			                        scanf("%d",&dataT.age);
			         			                        fflush(stdin);
			         			                        printf("\t\t\t\t\t\t\t\t\tSalary(Rs.):");
			         			                        scanf("%d",&dataT.salary);
			         			                        fflush(stdin);
			         			                        printf("\t\t\t\t\t\t\t\t\tWorking hours:");
			         			                        printf("\n\t\t\t\t\t\t\t\t\tStarting time:");
			         			                        scanf("%d",&dataT.stime);
			         			                        fflush(stdin);
			         			                        printf("\n\t\t\t\t\t\t\t\t\tEnding time:");
			         			                        scanf("%d",&dataT.etime);
			         			                        fflush(stdin);
			         			                        fseek(fp2,-recsize2,SEEK_CUR);
			         			                        fwrite(&dataT,recsize2,1,fp2);
												      }
												    break;  
												  }
												break;  
										    }
										case 2://Deleting the trainer info
										    {
										    	ft2=fopen("E:\\temp2.txt","wb+");
								                if(ft2==NULL)
								                 {
									  	                printf("Temp File not opened!!");
								  	                    exit(0);
   	     	                                            return 0;  	
								                  }
										    	rewind(fp2);
								                while(fread(&dataT,recsize2,1,fp2)>0)
								                  {
								                    if(strcmp(dataT.name,tname)!=0&&tid!=dataT.id)
										    	      {
										    	  	    fwrite(&dataT,recsize2,1,ft2);
												      }
										 	      }
												    fclose(ft2);
												    fclose(fp2);
												    remove("E:\\TrainerInfo.txt");
												    rename("E:\\temp2.txt","E:\\TrainerInfo.txt");
	                                             	    fp2=fopen("E:\\TrainerInfo.txt","rb+");
	                                                    if(fp2==NULL)
	                                                      {
	                                                   	    printf("\n\t\t\t\t\t\t\t\t\tFile2.1 not opened!!!");
	     	                                                exit(0);
   	     	                                                return 0;
													      }	
												printf("\n\t\t\t\t\t\t\t\t\tPress any key to continue..");
							                    getchar();
							                    system("cls");    
												break;  
										    }
										case 3://Exiting to the main trainer menu
										    {
										       printf("\n\t\t\t\t\t\t\t\t\tPress any key to continue..");
							                   getchar();
							                   system("cls");    
											   break;  	
											}
										default:
										printf("\n\t\t\t\t\t\t\t\t\tWrong Entry!!");
										goto tdatawrong;
										system("cls");
										break;		    
									  }     
								break;
							}
						case 3://Listing all the working trainers on the gym
							{
								printf("\n\t\t\t\t\t\t\t\t\tList of all Trainers");
								printf("\n\t\t\t\t\t\t\t\t\t********************");
   	    	                    rewind (fp2);
	                            while(fread(&dataT,recsize2,1,fp2)>0)
	                                { 
	                                  
	                                  printf("\n");
	                                  printf("\n\t\t\t\t\t\t\t\t\tName:");
			        		          puts(dataT.name);
			         	              printf("\t\t\t\t\t\t\t\t\tId:%d",dataT.id);
			         		   	      printf("\n\t\t\t\t\t\t\t\t\tAge:%d",dataT.age);
			        		          printf("\n\t\t\t\t\t\t\t\t\tSalary(Rs.):%d",dataT.salary);
			         	              printf("\n\t\t\t\t\t\t\t\t\tWorking hours(24hrs format):");
			         			      printf("\n\t\t\t\t\t\t\t\t\tStarting time:%d",dataT.stime);
			         			      printf("\n\t\t\t\t\t\t\t\t\tEnding time:%d",dataT.etime);
	                                } 
			                    printf("\n\t\t\t\t\t\t\t\t\tPress any key to continue.");  
	                            getchar();
			                    system("cls"); 
								break;
							}
						case 4://Exiting to the main menu
							{
								printf("\n\t\t\t\t\t\t\t\t\tPress any key to continue.");
								getchar();
								system("cls");
								goto top;
								break;
							}	
						default:
						printf("\n\t\t\t\t\t\t\t\t\tWrong choice!!");
						goto Tchoicewrong;
						break;
					 }	 
			   }
			   break;
		     }
		    case 6://Managing the equipment available in the gym
			 {
			 	int equipchoice;
			 	while(1)
			 	{
			 	menu();	
			 	printf("\n\n");	
			 	printf("\n\t\t\t\t\t\t\t\t\t(|--|)Equipment Management(|--|)");
			 	printf("\n\t\t\t\t\t\t\t\t\t********************************");
			 	printf("\n\t\t\t\t\t\t\t\t\t1.Add Equipment");
			 	printf("\n\t\t\t\t\t\t\t\t\t2.List all Equipments");
			 	printf("\n\t\t\t\t\t\t\t\t\t3.Find Equipment");
			 	printf("\n\t\t\t\t\t\t\t\t\t4.Exit");
			 	printf("\n\t\t\t\t\t\t\t\t\tEnter your choice:");
			 	scanf("%d",&equipchoice);
			 	fflush(stdin);
			 	system("cls");
			 	switch(equipchoice)
			 	   {
			 	   	  case 1://Adding a new equipment
			 	   	  	{
			 	   	  		addequip:
			 	   	  		printf("\n\t\t\t\t\t\t\t\t\tAdd equipment information");
			 	   	  		printf("\n\t\t\t\t\t\t\t\t\t*************************");
			 	   	  		printf("\n\t\t\t\t\t\t\t\t\tEquipment name:");
			 	   	  		gets(dataE.equip);
			 	   	  		fflush(stdin);
							printf("\t\t\t\t\t\t\t\t\tNo. of %s:",&dataE.equip);
							scanf("%d",&dataE.numbers);
							fflush(stdin);
							fwrite(&dataE,recsize3,1,fp3);
			         	    char YNequipment;
			                YNequipwrong:
			                printf("\n\t\t\t\t\t\t\t\t\tDo you want to add another equipment(input Y/N):");
			                scanf("%s",&YNequipment);
			                fflush(stdin);
			                system("cls");
			                if(YNequipment=='Y'||YNequipment=='y')
			                    {
			                      	goto addequip;
				                }
			               else if(YNequipment=='N'||YNequipment=='n')
			                    {
		      	                   break;
   			                    }
				            else
				                {
				  	              printf("\n\t\t\t\t\t\t\t\t\tWrong Entry!!");
				                  printf("\n\t\t\t\t\t\t\t\t\tPress any key to continue.");
			 	                  getchar();
			  	                  system("cls");
			  	                  goto YNequipwrong;
						       }		
							break;
				 	    }
				 	  case 2://List of all equipments
					   {
					   	    printf("\n");
					   	    printf("\n\t\t\t\t\t\t\t\t\tList of all equipments");
					   	    printf("\n\t\t\t\t\t\t\t\t\t**********************");
   	    	                rewind (fp3);
	                        while(fread(&dataE,recsize3,1,fp3)>0)
	                          {
	                          	printf("\n\t\t\t\t\t\t\t\t\tEquipemnt name:");
	                          	puts(dataE.equip);
								printf("\t\t\t\t\t\t\t\t\tTotal no:%d",dataE.numbers);  
								printf("\n\t\t\t\t\t\t\t\t\t**************************");
							  }
							printf("\n\t\t\t\t\t\t\t\t\tPress any key to continue..");
							getchar();
							system("cls");  
					   	    break;
					   }
					  case 3://Finding and editing the equipment information
					   {
					   	  char tequip[30];
					   	  int tweight,aequip;
					   	  edetwrong:
					   	  menu();	
					   	  printf("\n\n");
					   	  printf("\n\t\t\t\t\t\t\t\t\tEnter Equipment information");
				          printf("\n\t\t\t\t\t\t\t\t\t***************************");
					   	  printf("\n\t\t\t\t\t\t\t\t\tEquipment name:");
					   	  gets(tequip);
					   	  fflush(stdin);   
						  system("cls");  
						  int edatachoice;
				  		  MRwrong:
						  printf("\n\t\t\t\t\t\t\t\t\tWhat do you want to do with this data");
						  printf("\n\t\t\t\t\t\t\t\t\t1.Show");
						  printf("\n\t\t\t\t\t\t\t\t\t2.Modify");
						  printf("\n\t\t\t\t\t\t\t\t\t3.Remove");
						  printf("\n\t\t\t\t\t\t\t\t\t4.Exit");
						  printf("\n\t\t\t\t\t\t\t\t\tEnter your choice:");
						  scanf("%d",&edatachoice);
						  fflush(stdin);
						  system("cls");
						  switch(edatachoice)
								  {
								  	 case 1://Showing the equipment info
								  	 	{
								  	 	    rewind(fp3);
			                                while(fread(&dataE,recsize3,1,fp3)>0)
						                    {
						    	            if(strcmp(dataE.equip,tequip)==0)
						    	            {
									   	          printf("\n\t\t\t\t\t\t\t\t\tEquipment name:");
						    	  	              puts(dataE.equip);
						    	  	              printf("\t\t\t\t\t\t\t\t\tTotal no:%d",dataE.numbers);  
								            }
								            break;
							                }
								  	 		break;
									    }
								  	 case 2://Adding or removing the no. of equipment
								  	 	{
								  	 		char AR;
											int a,r;
								  	 		rewind (fp3);
	                                        while(fread(&dataE,recsize3,1,fp3)>0)
	                                          {
	                                          	if(strcmp(dataE.equip,tequip)==0)
	                                          	  {
	                                       	  	            ARwrong:
								  	 		                printf("\n\t\t\t\t\t\t\t\t\tAdd or Remove no. of ");
								  	                        puts(dataE.equip);
								  	 	                    printf("\n\t\t\t\t\t\t\t\t\tPress (A to add/R to remove):");
								  	 	                    scanf("%s",&AR);
								  	 	                    fflush(stdin);
								  	 	                    if(AR=='a'||AR=='A')
								  	 	                      {
								  	 	      	                printf("\n\t\t\t\t\t\t\t\t\tAdd(in no.):");
								  	 	      	                scanf("%d",&a);
								  	 	      	                fflush(stdin);
								  	 	      	                dataE.numbers=dataE.numbers+a;
								  	 	      	                fseek(fp3,-tempsize1,SEEK_CUR);
								  	 	      	                fwrite(&dataE.numbers,tempsize1,1,fp3);
											                  }
											                else if(AR=='r'||AR=='R')
								  	 	                      {
								  	 	      	                printf("\n\t\t\t\t\t\t\t\t\tRemove(in no.):");
								  	 	      	                scanf("%d",&r);
								  	 	      	                fflush(stdin);
								  	 	      	                dataE.numbers=dataE.numbers-r;
								  	 	      	                fseek(fp3,-tempsize1,SEEK_CUR);
								  	 	      	                fwrite(&dataE.numbers,tempsize1,1,fp3);
											                  }
													        else
													          {
													         	printf("\n\t\t\t\t\t\t\t\t\tWrong Entry!!");
													  	        goto ARwrong;
													          }   
												  }
												break;   
										      }
								  	 		break;
									    }
									  case 3://Removing the equipment
									    {
									    	
					   	                   ft3=fopen("E:\\temp3.txt","wb+");
				  		                   if(ft3==NULL)
							                   {
				  		          	              printf("Temp File not opened!!");
							  	                  exit(0);
   	     	                                      return 0;
							                  }
									       rewind(fp3);
									       while(fread(&dataE,recsize3,1,fp3)>0)
									       {
											   	    if(strcmp(dataE.equip,tequip)!=0)
											   	      {
											   	      	fwrite(&dataE,recsize3,1,ft3);
													  }
										    }    
											fclose(ft3);
											fclose(fp3);
											remove("E:\\EquipmentInfo.txt");
											rename("E:\\temp3.txt","E:\\EquipmentInfo.txt");
	                                        fp3=fopen("E:\\EquipmentInfo.txt","rb+");
	                                        if(fp3==NULL)
	                                            {
	                                                  	printf("\n\t\t\t\t\t\t\t\t\tFile3 not opened!!!");
	     	                                            exit(0);
   	     	                                            return 0;
												}
	                                        break ;   
									    }  
									  case 4://Exiting to the equipment menu
									    {
									    	printf("\n\t\t\t\t\t\t\t\t\tPress any key to continue..");
								            getchar();
								            system("cls");
								            break;
									    }
									  default:
									  printf("\n\t\t\t\t\t\t\t\t\tWrong choice!!");
									  printf("\n\t\t\t\t\t\t\t\t\tPress any key to continue..");
									  getchar();
									  goto MRwrong;
									  break;
							break;
					   }
					  case 4://Exiting to the main menu
					   {
					   	  printf("\n\t\t\t\t\t\t\t\t\tPress any key to continue..");
					      getchar();
			              system("cls");
			 			  goto top;			
				          break;
					   }
					  default:
					  printf("\n\t\t\t\t\t\t\t\t\tWrong choice!!");
				      printf("\n\t\t\t\t\t\t\t\t\tPress any key to continue..");
					  getchar();	
					  break;   
					break;    
				   }
			   }
			 } 
			case 7://Exiting from the program
			 {	
			   
			   exit(0);
   	     	   break;
		     }
			default:
			printf("\n\t\t\t\t\t\t\t\t\tout of range");
			goto flag;
			break;
	    }
     }
   }
   fclose(fp1);
   fclose(fp2);
   fclose(fp3);
   fclose(fp4);
   return 0; 
}
void menu()
  {
        printf("\n\t\t\t\t\t\t\t      ________                                        ________");
  	    printf("\n\t\t\t\t\t\t\t     |        |                                      |        |");
  	    printf("\n\t\t\t\t\t\t\t   __||||||||||                                      ||||||||||__");
  	    printf("\n\t\t\t\t\t\t\t _|  ||||||||||______________________________________||||||||||  |_");
  	    printf("\n\t\t\t\t\t\t\t|_|  ||||||||||______________________________________||||||||||  |_|");
  	    printf("\n\t\t\t\t\t\t\t  |__||||||||||                                      ||||||||||__|");
  	    printf("\n\t\t\t\t\t\t\t     ||||||||||                                      ||||||||||");
  	    printf("\n\t\t\t\t\t\t\t     |________|                                      |________|");
  };
