#include <iostream>
#include <cstdlib>

using namespace std;

int chkValidNumber(char* chk_valid)
{
    
    int deci_counter = 0;
    int valid = 0; //return value; return 1 if not valid;
    
    int i;
    int neg_counter = 0;
    for (i = 0; chk_valid[i] != '\0'; i++)
    {
        
        if ( chk_valid[i] == 45 && neg_counter == 0)
        {
            neg_counter += 1;
            //increase counter, go to next position.
        }
        else
        {
            if ( chk_valid[i] == 46 && deci_counter == 0 )
            {
                deci_counter+=1;
            }
            else if( chk_valid[i] == 46 && deci_counter == 1 ) //more than 2 decimal points
            {
                valid = 1;
                break;
            }
            else if ( chk_valid[i] < 48 || 57 < chk_valid[i] )
            {
                valid = 1;
                break;
            }
        }
    }
    return valid;
}

int main(int argc, char* argv[])
{
    if(argc != 4) // error case: argc less is not equal to 4
    {
        cout <<  "bm <number> <+-x/> <number><ENTER>" << endl;
    }
    else
    {
        if ( chkValidNumber(argv[1]) == 0 &&
             chkValidNumber(argv[3]) == 0 &&
             strlen(argv[2]) == 1)
        {
            double left  = atof(argv[1]);
            double right = atof(argv[3]);
            
            switch( argv[2][0])
            {
                case '+':
                    cout << left+right << endl;
                    break;
                case '-':
                    cout << left-right << endl;
                    break;
                case 'x':
                    cout << left*right << endl;
                    break;
                case '/':
                    cout << left/right << endl;
                    break;
                default: // error case: not vali operator.
                    cout <<  "bm <number> <+-x/> <number><ENTER>" << endl;
                    break;
            }
        }
        else // error case: not number or operator length is not equal to 1.
        {
            cout <<  "bm <number> <+-x/> <number><ENTER>" << endl;
        }
    }
    return 0;
}

