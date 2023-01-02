//! algorthim to solve this problem 
//* اول خطوة هنعمل ستاك فاضى 
//* تانى خطوة لو لاقيت اى قوس مفتوح هعمل بوش فى الاستاك 
//* تالت خطوة لو لاقيت اى رقم هظهرة
//! رابع خطوة بالنسبة لى العمليات الحسابية 
//* هضيف العملية فى الاستاك 
//* ولكن فى حالة ان العملية اللى هتنضاف اكبر من او تساوى العملية اللى موجودة فى التوب 
//* هنفضل نعمل بوب للعملية لحد ما اقدر اضيفها 
//! فى حالة لاقيت قوس مقفول هعمل بوب لحد ما لاقى فاتحة القوس دة 

//* 1. Create a empty stack & empty string for output
//* 2. loop on the infix expression 
//* 3. on the the loop 
//! if its a digit then add it to the output 
//* يعنى فى حالة انه كان رقم ضيفة على ال اوت بوت 
//! else if ( the add it to the stack 
//* else if ) pop from stack to output until you reach (
//! if it s an operator the pop from stack until you can push it to the stack 


// 9 * 4 - 2

//* 4. if the stack is not empty then pop to the output the rest 
//* 5. print the output 



#include<iostream>
#include<stack>//مكتبة عشان استخدم الاستاك
#include<algorithm>
using namespace std;
int priority(char c)
{
    if(c=='-'||c=='+')
    {
        return 1;
    }
    else if(c=='*'||c=='/')
    {
        return 2;
    }
    else 
    return 0;

}
//infixToPostfix("9*(4-2)");//
string infixToPostfix(string exp){
    stack<char> s;
    string output="";
    for(int i=0; i<exp.length() ;i++){
        if(exp[i] == ' ') continue; 
        if(isdigit(exp[i])){
            output+=exp[i];
        }
        else if(exp[i]=='(')
        {
            s.push('(');
        }
        else if(exp[i]==')')
        {   
            while(s.top()!='('){
            //!هنا انا بعمل لوب طول ما التوب مش بيساوى فتحة القوس 
            //* يبقى حطلى التوب فى الاوت بوت 
            //* وبعد كدة شيلة بالبوب 
                output +=s.top();
                s.pop();
            }
            s.pop();
        }
        else{
            //9-4*2 
            while(!s.empty() && priority(exp[i]) <= priority(s.top()))
            {
                output+=s.top();
                s.pop();
            }
            s.push(exp[i]);
        }
    }
    while(!s.empty())
    {
        output+=s.top();
        s.pop();
    }
    return output;

}

//funtion to calculate the output of postfix 
float cal(float n1, float n2, char op)
{
    if(op=='+'){
    
        return n1+n2;}
    
    else if(op=='-'){
    
    return n1-n2;}
    
     else if(op=='*'){
    
    return n1*n2;}
       
    else if(op=='/'){

    return n1/n2;}
    
    else {return 0;}
    
 
}




// Function to evaluate a postfix expression
float evaluatePostfix(string exp)
{
    string newExp = infixToPostfix(exp);
    stack<float> s;//عملت الدالة والاستاك من نوع فلوت عشان ممكن يطلع ارقام كسرية
    for(int i=0;i<newExp.length();i++)
    {
        if(isdigit(newExp[i]))
        {
            s.push(newExp[i]-'0');//لية الحوار دة عشان 
            //0=48 :  1=49 : 2=50 : 3=51
            //51-48=3 
        }
        else{
            float result=0.0;
            float second = s.top();
            s.pop();
            
            float first = s.top();
            s.pop();
            
            result=cal(first,second, newExp[i]);
            s.push(result);
        }
    }
    return s.top();
    
}//end of the function 
    
int main()
{
    string infix=("9-4*2");//
    cout<<"postfix Expression (First Output )"<<infixToPostfix(infix);
    string text="9-4*2";
    cout<<"expression equal : "<<endl;
    cout<<evaluatePostfix(text)<<endl;
    
    
    
 
}
