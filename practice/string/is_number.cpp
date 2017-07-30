//verify a string is a number
//can contains 'e','.' etc.
class Solution {
public:
    bool isNumeric(char* string) {
        if (string==nullptr) return false;
        while (*string==' ') string++;//remove blank
		//remove + , -
        if (*string&&*string=='+'||*string=='-') string++;
        int count_num=0,count_point=0,count_e=0;
        while (*string&&(*string=='.'||isdigit(*string))) 
    		*string++=='.' ? count_point++ : count_num++;
        if (count_point>1||count_num<1) return false;
        if (*string&&(*string=='e'||*string=='E')) {
            string++;
            if (*string&&(*string=='+'||*string=='-')) string++;
            while (*string&&isdigit(*string)) {string++;count_e++;}
            if (count_e<1) return false;
        }
        while (*string&&*string==' ') string++;
        return *string=='\0';
    }
};
