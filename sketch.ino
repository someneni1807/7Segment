
volatile char a[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
volatile char b[]={0xbf,0x86,0xdb,0xcf,0xe6,0xed,0xfd,0x87,0xff,0xef};
void setup() {
  // put your setup code here, to run once:
  volatile long i ,j,k,l,x;
  volatile char *dirf, *outf;
  volatile char *dirk,*outk;
  dirf=0x30;dirk=0x107;
  outf=0x31;outk=0x108;
  *dirf=0xff;*dirk=0xff;
  while(1){
    for(i=0;i<10;i++){
      for (j=0;j<10;j++){
        for (k=0;k<10;k++){
          for(l=0;l<10;l++){
            for (x=0;x<10;x++){
                thousdigit(a[i]);
                delay(10);
                hundrdigit(a[j]);
                delay(10);
                tensdigit(a[k]);
                delay(10);// delay b/w change tens to ones
                onesdigit(a[l]);
                delay(10);//delay b/w change ones  to tens
            }
          }
        } 
      }
    }

  }


}
void thousdigit(char num){
  volatile char *outf,*outk;
  outf=0x31;outk=0x108;
  *outk=0x0f;
  *outf=num;
  *outk=0x0e;
}
void hundrdigit(char num){
  volatile char *outf,*outk;
  outf=0x31;outk=0x108;
  *outk=0x0f;
  *outf=num;
  *outk=0x0d;
}
void tensdigit(char num){
  volatile char *outf,*outk;
  outf=0x31;outk=0x108;
  *outk=0x0f;// turn off both digits
  *outf=num; //set the segment no
  *outk=0x0b;//turn on the tenth place digit

}
void onesdigit(char num){
  volatile char *outf,*outk;
  outf=0x31;outk=0x108;
  *outk=0x0f;
  *outf=num;
  *outk=0x07;
}
void loop() {
  // put your main code here, to run repeatedly:



}
