/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <math.h>

 #define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })


unsigned int get_fsind(int fs);

int main()
{
    printf("Hello World");
    unsigned int fsind = 0; //sampling rate index
    int fs = 0; //sampling frequency
    float fscal = 0;
    float Nf  = 0; //frame_size N
    float Nms = 0;
    float D = 0; //algorithmic delay
    float Z = 0;
    unsigned int bitrate = 0;
    unsigned int Nbytes = 0;
    
    printf("Enter sampling frequency (8000, 16000, 44100, 48000): ");
    scanf("%d", &fs);
    
    printf("Enter frame duration (7.5ms or 10ms) enter only value: ");
    scanf("%f", &Nms);
    printf("Frame duration = %f \n", Nms);
    
    if(fs == 44100)
     fscal = 1.08843;
    else
     fscal = 1;
     
    printf("fscal = %f\n", fscal);
    
    fsind = get_fsind(fs);
    printf("fs ind = %u\n", fsind);
    
    Nf = (fs*fscal*Nms)/1000;
    printf("Nf = %f\n", Nf);
    printf("Frame duration Nms = %f \n", Nms);
    
    if(Nms == 7.500000)
    {
     Z = Nf * 0.37500;
     printf("I am here\n");
    }
    else //for 10ms
    {
        printf("fffff\n");
     Z = Nf * 0.3;
    }
    
    printf("Z = %f\n", Z);
    
    D = (1000 * ((2*Nf)-(2*Z)))/fs;
    printf("algorithmic delay = %f", D);
    
    printf("Enter bit rate required : ");
    scanf("%d", &bitrate);
    printf("bitrate = %u \n", bitrate);
    
    Nbytes = (bitrate*Nms*fscal)/8000;
    
    printf("Nbytes = %u",Nbytes);
    
    if(Nbytes > 400)
      printf("reduce bitrate for accurate LC3 encoding");
    if(Nbytes < 20)
      printf("reduce bitrate for accurate LC3 encoding");
    return 0;
}

unsigned int get_fsind(int fs)
{
    unsigned int fsind_tmp;
    fsind_tmp = min(4, ((fs/8000)-1));
    return fsind_tmp;  
}


