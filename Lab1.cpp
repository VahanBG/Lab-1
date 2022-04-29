#include <string>
#include<iostream>
#include<cstring> 
#include<fstream>
std::string capital(std::string word)
{
        
       int size = word.length();
       if ((word[0]>='a')&&(word[0]<='z')){word[0]=word[0]-32;}
       for(int i = 1;i<size;i++)
        {
if((((word[i]>='A')&&(word[i]<='Z'))||((word[i]>='a')&&(word[i]<='z')))!=true)
            {
            if ((word[i-1]>='a')&&(word[i-1]<='z')){word[i-1]=word[i-1]-32;}
            if ((word[i+1]>='a')&&(word[i+1]<='z')){word[i+1]=word[i+1]-32;}
            }
        }
          return word;
};
int main (int argc, char *argv[])
{
	char  nameof_file[256];
        if (argc <2)
    {
        std::cout<<"Input name of file, please: ";
        fgets(nameof_file, 256, stdin); 
        for (int x=0; nameof_file[x]; x++)
	{if (nameof_file[x] == '\n'){nameof_file[ x] = '\0';}}
    }
        printf("name of  file: %s\n", nameof_file);
        std::string path1=nameof_file;
        std::ifstream fin;
        fin.open(path1);
        if(!fin.is_open()){std::cout<<"The file you selected was not uploaded"
	<<std::endl;}
        else
        {
        std::cout<<"The file you selected was successfully uploaded"<<std::endl;
        std::string str1;
        std::string str2="";
        while(!fin.eof())
              {
                str1 = "";
               getline(fin,str1);
               std::cout<<str1;
               str2+=str1;
              }

        std::ofstream fout;
        fout.open(path1);
        if(!fout.is_open())
         {std::cout<<"nor file chi stexcvel"<<std::endl;}
         else{fout<<capital(str2);}
               fout.close() ;
        }

                fin.close();

    
    return 0;
}
