class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) 
	{
         if(bits.size() == 1)
         {
         	if(bits[0] == 0)
         	return true;
         	
         	return false;
		 }

		 int l=0;
		 while(l < bits.size())
		 {
		 	if(l == bits.size()-1)
		 	{
		 	   	if(bits[l] == 0)
		 	   	return true;
                
                return false;
		    }
		 	else if((l < bits.size()) and (l+1) < (bits.size()))
		 	{
                if(bits[l] == 1 and bits[l+1] == 0)
                l = l + 2;
                else if(bits[l] == 1 and bits[l+1] == 1)
                l = l + 2;
                else
                l++;
		    }
		 }
		 return false;
    }
};