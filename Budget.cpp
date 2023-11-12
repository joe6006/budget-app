#include <iostream>
#include <locale>
#include <string>
#include <vector>
 #include <numeric>
// declaring functions 
double fiftyRule(double& monthly, double& fifty, double& thirty, double& twenty, std::string& input);
double seventyRule(double& monthly, double& seventy, double& twenty, double& ten, std::string& input);
double seventyFiveRule(double& monthly, double& seventy_five, double& fifteen, double& ten, std::string& input);
double sixtyRule(double& monthly, double& sixty, double& thirty, double& ten, std::string& input);
void choice(int& budgetselect);
void choiceCheck(bool& ref_menuLoop,double &ref_usersMonthlyIncome, double& ref_needs, double& ref_wants,double& ref_debt_money, double& ref_savings, std::string& ref_input, double& ref_investments, int& ref_budgetSelection);
//using a template to validate strict input 
template <typename T>
T num_check(T a) {

   while (!std::cin) {
                     std::cout << "invaid input "<< std::endl;
                     std::cin.clear();
                     std::cin.ignore(100, '\n');
                     
                     };

   return a;
};

//class for 
class expenseList {
        private: std::vector<double> cost = {};
                 std::vector<std::string> cost_name = {};
        
        public: //set and get private members

                  void set_cost(double value) {
                        cost.push_back(value);
                }
                 double get_cost(double index) {
                        for (int i = 0; i < cost.size(); i++) {
                                std::cout<<cost[i]<< std::endl;
                        };

                        return cost[index];
                }

                //set and get string
                void set_costName(std::string value) {
                        cost_name.push_back(value);
                }

                std::string get_costName(std::string ind) {
                        for (int i = 0; i < cost_name.size(); i++) {
                                std::cout<<cost_name[i]<< std::endl;
                        };
                        return nullptr;
                }

                 double add(double value){
                        //using accumulate to sum vector.
                          double sum = std::accumulate(cost.begin(), cost.end(), 0);
                          std::cout<<"your total monthly expenses: "<<sum<<std::endl;
                        return sum;
                }


                //users list

                void userout(std::string ind, double value){
                        for(int i = 0; i < cost_name.size(); i++){
                                std::cout<<cost_name[i]<< ":  "<< cost[i]<<std::endl;
                        };

                }

                //users input for list
                void usersinput(std::string name, double num){
                        
                        while(std::cin){  
                               //name of expense
                                 std::cin>>name;
                                 if(name == "done"){
                                          break;
                                };   
                                 set_costName(name);
                                

                                //cost of expense
                                std::cin>>num;
                                
                                if(!std::cin){
                                        do{
                                                num_check(num);
                                                std::cout<<"please input the cost of this expense."<<std::endl;
                                                std::cin>>num;
                                                if(std::cin){
                                                        std::cout<<"thank you, you may continue"<<std::endl;
                                                         set_cost(num); 
                                                        break;
                                                };
                                        }while(!std::cin);
                                
                                }else{set_cost(num); };                             
                                
                        };
                        
                }
        
};


//the main program
int main(){

    //declaring variables
    double usersMonthlyIncomes{};
    int budgetSelections{};
    double need{};
    double want{};
    double saving{};
    double debt_moneys{};
    double investment{};
    bool menuLoops = false;
    std::string options = "options";
    std::string continu = "continue";
    std::string settings = "settings";
    std::string inputs = "";
    //var to be used by class
    double number;
    std::string name;
    double sum;
    
    choice(budgetSelections);


//running the rules of budget depending on the users choice using a switch case statement
//this do while loop prevents the user from continuing until that person has chosen an available option
    
    choiceCheck( menuLoops,usersMonthlyIncomes, need,  want, debt_moneys, saving, inputs, investment, budgetSelections);



   //options
    std::cout<<"If you wish to change plans type options; if not type continue."<<std::endl;  
    while(inputs != options || inputs != continu){
      
         std::cin>>inputs;
         if (inputs == options){
            std::cout<<"You will now be sent back to budget selection"<<std::endl;
            choice(budgetSelections);
            choiceCheck( menuLoops,usersMonthlyIncomes, need,  want, debt_moneys, saving, inputs, investment, budgetSelections);
            break;
         }else if (inputs == continu){ 
            break;
         }else { 
            std::cout<<"try again"<< std::endl;
         
            continue;
         };
    };
   
    std::cout<< "Great job so far let's move on to getting your monthly expenses."<<std::endl;
    std::cout<< "Below you are a creating a list of your monthly expenses,"<<std::endl<< "begin with the name, hit ENTER and type in the cost. type 'done' when finished"<<std::endl;
    //here we are creating a class object so the user can begin the list
    //if the user types "done" then the list is complete and the program is done for now.
    expenseList userList;
    userList.usersinput(name, number);
    userList.add(sum);
    
  
    
    std::cout<<"that's it for now..."<<std::endl;
    std::cout<<"thank you for taking the time to check out this project!"<<std::endl;

        
   


    return 0;
    
}


//function defintions
void choiceCheck(bool& ref_menuLoop,double &ref_usersMonthlyIncome, double& ref_needs, double& ref_wants,double& ref_debt_money, double& ref_savings, std::string& ref_input, double& ref_investments, int& ref_budgetSelection){
         do{
        switch(ref_budgetSelection){

            case 1:  
                    fiftyRule(ref_usersMonthlyIncome, ref_needs, ref_wants, ref_savings, ref_input);
                     
                     ref_menuLoop = true;                    
            break;

            case 2: 
                    seventyRule(ref_usersMonthlyIncome, ref_needs, ref_savings, ref_debt_money,ref_input);
                   
                   ref_menuLoop = true;      
            break;

            case 3: 
                    seventyFiveRule(ref_usersMonthlyIncome, ref_needs, ref_investments, ref_savings,ref_input);
                    ref_menuLoop = true;      
            break;

            case 4: 
                    sixtyRule(ref_usersMonthlyIncome, ref_needs, ref_savings,ref_wants,ref_input);
                 
                    ref_menuLoop = true; 
            break;

            default:
                     num_check(ref_budgetSelection);
                     choice(ref_budgetSelection);
                        
       }

    }while(!ref_menuLoop);
}

void choice(int& budgetselect){
     //picking an option
    std::cout<<"Please choose a suffiecient budgeting option"<< std::endl;
    //list different options and make selections
    std::cout << "1. 50/30/20"<< std::endl;
    std::cout << "2. 70/20/10 " << std::endl;
    std::cout << "3. 75/15/10 " << std::endl;
    std::cout << "4. 60/30/10" << std::endl;
    std::cin>> budgetselect;
}


double fiftyRule(double& monthly, double& fifty, double& thirty, double& twenty, std::string& input){
     std::cout<< "please input your monthly pay after tax"<< std::endl;
     std::cin>>monthly;
     input = "";
     num_check(monthly);
     if(monthly < 100){
         std::cout<<"Your monthly income must be over $100, Please enter a valid amount";
         std::cin>>monthly;
     }else if(monthly > 0){
        //the math
         fifty = (monthly * 50) / 100;
         thirty = (monthly * 30) / 100;
         twenty = (monthly * 20) / 100;
         std::cout<< "This is what you have for your expenes: " << fifty<< std::endl;
         std::cout<< "This is for your wants: "<< thirty << std::endl;
         std::cout<< "And this is for your savings: " << twenty<< std::endl;
         
     };

    return monthly;
}


double seventyRule(double& monthly, double& seventy, double& twenty, double& ten, std::string& input){
    std::cout<< "please input your monthly pay after tax"<< std::endl;
    std::cin>>monthly;
      num_check(monthly);
     if(monthly < 100){
          std::cout<<"Your monthly income must be over $100, Please enter a valid amount";
          std::cin>>monthly;
     }else if(monthly > 0){
        //the math
         seventy = (monthly * 70) / 100;
         twenty = (monthly * 20) / 100;
         ten = (monthly * 10) / 100;
         std::cout<< "This is what you have for your expenes: " << seventy << std::endl;
         std::cout<< "This is for your savings: "<< twenty << std::endl;
         std::cout<< "And this is for your debt repayments: " << ten << std::endl;
         
      
     };
    return monthly;

}

double seventyFiveRule(double& monthly, double& seventy_five, double& fifteen, double& ten, std::string& input){
    std::cout<< "please input your monthly pay after tax"<< std::endl;
    std::cin>>monthly;
   num_check(monthly);
    if(monthly < 100){
          std::cout<<"Your monthly income must be over $100, Please enter a valid amount";
         std::cin>>monthly;
     }else if(monthly > 0){
        //the math
         seventy_five = (monthly * 75) / 100;
         fifteen = (monthly * 15) / 100;
         ten = (monthly * 10) / 100;
         std::cout<< "This is what you have for your expenes: " << seventy_five << std::endl;
         std::cout<< "This is for your investments: "<< fifteen << std::endl;
         std::cout<< "And this is for your savings: " << ten << std::endl;
         
       
     };

    return monthly;

}


double sixtyRule(double& monthly, double& sixty, double& thirty, double& ten, std::string& input){
    std::cout<< "please input your monthly pay after tax"<< std::endl;
    std::cin>>monthly;
    num_check(monthly);
    if(monthly < 100){
          std::cout<<"Your monthly income must be over $100, Please enter a valid amount";
         std::cin>>monthly;
     }else if(monthly > 0){
        //the math
         sixty = (monthly * 60) / 100;
         thirty = (monthly * 30) / 100;
         ten = (monthly * 10) / 100;
         std::cout<< "This is what you have for your expenes: " << sixty << std::endl;
         std::cout<< "This is for your savings: "<< thirty << std::endl;
         std::cout<< "And this is for your wants: " << ten << std::endl;
         
      
     };

    return monthly;

}






