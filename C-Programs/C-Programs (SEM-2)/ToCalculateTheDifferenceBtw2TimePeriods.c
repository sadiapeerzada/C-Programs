#include <stdio.h>
struct time {
	int hr;
	int min;
	int sec;
} t1,t2,tf;
int main(){
	int s1,s2,d;
	printf("Format - HH:MM:SS\n");
	printf("Time 1 : ");
	scanf("%d:%d:%d",&t1.hr,&t1.min,&t1.sec);
	printf("Time 2 : ");
	scanf("%d:%d:%d",&t2.hr,&t2.min,&t2.sec);
	s1=t1.hr*3600+t1.min*60+t1.sec;
	s2=t2.hr*3600+t2.min*60+t2.sec;
	d=(s1>=s2)?(s1-s2):(s2-s1);
	tf.hr=d/3600;
	tf.min=(d%3600)/60;
	tf.sec=d%60;
	printf("Diffrence : %02d:%02d:%02d",tf.hr,tf.min,tf.sec);
}