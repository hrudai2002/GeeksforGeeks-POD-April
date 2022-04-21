string remove(string str){
        // code here
        string output;
        while(1)
        {
            output="";
            for(int i=0;i<str.size();i++)
            {
                if(i==0 && str[i]!=str[i+1])
                {
                    output+=str[i];
                }
                else if(i==str.size()-1 && str[i]!=str[i-1])
                {
                    output+=str[i];
                }
                else if(str[i]!=str[i-1] && str[i]!=str[i+1])
                {
                    output+=str[i];
                }
            }
            if(output==str)
            break;
            
            str = output;
        }
        return output;
    }
