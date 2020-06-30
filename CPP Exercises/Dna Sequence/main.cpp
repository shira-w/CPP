
/*#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4996)
#endif*/

#include "DnaSequence.h"
int main()
{
	try {
		char c[] = "C";
		DnaSequence dna(c);
		std::cout << dna;
		std::string str = "GT";
		DnaSequence dna2(str);
		std::cout << dna2;
		DnaSequence dna3(dna2);
		std::cout << dna3;
		dna2 = dna2;
		std::cout << dna2;
		dna2 = "G";
		std::cout << dna2;
		char c2[] = "CT";
		dna2 = c2;
		std::cout << dna2;
		std::string abimush = "TTT";
		dna2 = abimush;
		std::cout << dna2;
		std::cout << (dna2 == dna2);
		std::cout << (dna2 != dna3);
		std::cout << dna2[1];
		//std::cout << dna2[10];
		char con = 'A';
		dna2[0] = con;
		char cooom = dna2[0];
		std::cout << "----------------------------"<<cooom;
		std::cout << dna2;
		dna2[0] = 'A';
		std::cout << dna2;
		std::cout << dna2.length();
		dna2.writeToFile("dna.txt");
		dna3.readFromFile("to_your_handle.txt");
		std::cout << dna3;
		/*DnaSequence dna4=dna3.slice(7, 8);
		std::cout << dna4;*/

		char* s=new char[4];
		strcpy(s, "ssss");
		s[1] = 'y';
		std::cout << s;
	}
	catch (InvalidNucleotid& id)
	{
		std::cout << id.what() << std::endl;
	}
	catch (InvalidDna& id)
	{
		std::cout << id.what() << std::endl;
	}
	catch(std::out_of_range& id)
	{
		std::cout << id.what() << std::endl;
	}

		

}

#ifdef _MSC_VER
#pragma warning(pop)
#endif
