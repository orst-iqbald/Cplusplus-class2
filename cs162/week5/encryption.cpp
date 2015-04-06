/*********************************************************************
 * ** Program Filename: Encryption.h along w/ encryption.cpp, main.cpp, and makefile
 * ** Author: Danish Iqbal
 * ** Date: 11/1/14
 * ** Description: header for encryption lab 5. Defines class functions
 * ** Input: Class objects for Encryption (parent class) and derived classes substitions and transpoe
 * ** Output: Set functions nad your encrypted message in encryption of your choice (subsition or transposition)
 * *********************************************************************/


#include "encryption.h"
/* Function: set input
 * Description: this takes input from the file removed spaces adn sets it as input for the mssage to be encrypted
 * Date: 11/2
 * Input: string message from file
 * Output: message wthat's w/o spaces or numberical characters
 */
	
void Encryption::setInput(string eInput)// Taking out numbers and spaces from message that need to be encrypted
{
        int alpha_count = eInput.length();
        char message_array[alpha_count];// array to hold message w/o letters

        int k=0;// number of letters
        for(int i=0; i< alpha_count; i++){
                if(isalpha(eInput.at(i))){
                message_array[k] = tolower(eInput.at(i));
                k++;
                }
        }
	char message_array2[k];// this creates an array w/o any trailing spaces since message array is the length of th emssage (including spaces)
	for(int i=0; i<k; i++)
		message_array2[i] = message_array[i];
	string str(message_array2);
	
	input = message_array;// the final input w/o spaces adn numbers
}	

// Function that returns lenght of input. Will be used in subsequent derived clases
int Encryption::length()
{
	return input.length();// length of the final input w/o spaces
}
/*********************************************************************
 * ** Function: dedupe() of the Substition class
 * ** Description: removes duplicated letters from the message you wan tot encrypt
 * ** Parameters: string message
 * ** Pre-Conditions: needs string message
 * ** Post-Conditions: will give you back yoru encrypted message
 * *********************************************************************/

string Substitution::dedupe()// this takes out duplicate letters from the message
{

	int k = input.length();
	char message_array[k];// making an array that's as long as de-spaced message
	for(int i=0; i<k; i++)
		message_array[i] = input.at(i);// filling in array w/ de-spaced essage

        char dedupe[k];// aray to hold deduplicated message
        int pos=0;// counter for position
        int rep=0;// counter for repetition of letters
        for(int i=0; i<k; i++){// double for loop to check if there is repetition of letter
           for(int j=(i+1); j<k; j++){
                   if(message_array[i] == message_array[j]){
                        rep++;}
                   }
           if(rep==0){// fi there is no repetiion move forward
                   dedupe[pos] = message_array[i];
                   pos++;}
           else{// if there is repetition move forward 2 spaces
                   dedupe[pos] = message_array[pos+2];
                   rep=0;
                   }    
        }               
            
        int dedupe_length =0;// counter for size of deduped message
        for(int i=0; i<k; i++){
                if(isalpha(dedupe[i])){ 
                dedupe_length++;
                }
        }
        int dcounter=0;// will be length of de-duped message
        char dedupe_msg[dedupe_length];// array of deduped message 
        for(int i=0; i<dedupe_length; i++)
                if(isalpha(dedupe[i])){
                dedupe_msg[dcounter] = dedupe[i];
                dcounter++;
        }// this takes out trailing spaces and character and consolidates deduped message

        char alphabet[27] = "abcdefghijklmnopqrstuvwxyz";// alphabet array to insert message into
        for(int i=0; i<27; i++){// placing in blanks in alphabet array when encrypted message and alphabet letters match
                for(int j=0; j<dcounter; j++){
                   if(alphabet[i] == dedupe_msg[j])
                        alphabet[i]=' ';
                }
        }	 
// shortenign the alphabet array to new alpha after removal of same characters in the mssage 
        char newalpha[27-dcounter];
        int j=0;
        for(int i=0; i< 27; i++){
                if(isalpha(alphabet[i])){
                        newalpha[j] = alphabet[i];
                        j++;}
        }
// concatenating new alpha array to deduped message array in the 2 forloops below
        char concatanate[27];
        for(int i=0; i < dcounter; i++){
                concatanate[i] = dedupe_msg[i];
        }

        for(int i=dcounter; i<26; i++){
                concatanate[i] = newalpha[i-dcounter];
        }

// making new array for user to shit the letters by position ofo their choice
        char encrypt[26];
        int position = shift;
                
        int i;
        for(i=0; i<(26-shift); i++){
                encrypt[i] = concatanate[position];
                position++;
        }

        for(int count=0; count<shift; count++){
                encrypt[i] = concatanate[count];
                i++;
        }
// array for finaly encrypted message wthat will be returned afte shifting
	char encrypt2[27];

        for(int i=0; i<27; i++)
               encrypt2[i] = encrypt[i];
	
	return encrypt2;
}
/*********************************************************************
 * ** Function: tranposed (from the transpose clase)
 * ** Description: Takes mesage and places it in an array that's later transposed.. Prints message back out ot user
 * ** Parameters: string message 
 * ** Pre-Conditions: nees string message
 * ** Post-Conditions: prints our the string messages that's been encrypted through an array that's later transposed
 * *********************************************************************/
string Transpose::transposed()
{
	int k = input.length();
	int keye = getKey();

	int num_length = 1;
	if(keye > 0){
	   for( num_length=0; keye>0; num_length++){
		keye = keye/10;
	    }
	}

        int width = (int)((k/num_length)+(1));// thi swil be width of tranposed array
        
        char transpose[num_length][width];// creating of 2d array
  
        char message_array[k];// importing message into array 
        for(int i=0; i<k; i++)
                message_array[i] = input.at(i);
      
        int p=k;// placing message into transpoed array
        for(int i=0; i<num_length; i++){
                for(int j=0; j<width; j++){
                        transpose[i][j] = message_array[p];
                        p--;
                }
        }

	char transposed_message[p];// reversing message for reveose transposition.
	for(int i=0; i<num_length; i++){
                for(int j=0; j<width; j++){
                        transposed_message[p] = transpose[i][j];
			p++;
	}
	}
	return transposed_message;
}
