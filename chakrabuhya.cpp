//Approach: Recursion Method

#include <bits/stdc++.h>
using namespace std;
#define ll long long


bool CheckPass(ll current_circle, ll current_power, ll skip, ll recharge, vector<ll>&enemy_powers, bool IsSkipPrev, ll initial_power){
    
    //base case
    if(current_circle>10) return true;
    
    //special enemies
    if(current_circle==3 || current_circle==7){
         if(!IsSkipPrev){
             enemy_powers[current_circle]+=enemy_powers[current_circle-1]/2;
         }
    }
    
    
    //fight check
    if(enemy_powers[current_circle]<=current_power){
        current_power-=enemy_powers[current_circle];
        return CheckPass(current_circle+1,current_power,skip,recharge, enemy_powers, false, initial_power);
    }
    
    //skip and recharge option
    else{
        bool Choose_Skip=false;
        if(skip>0){
            Choose_Skip=CheckPass(current_circle+1,current_power,skip-1, recharge, enemy_powers, true, initial_power);
        }
        
        bool Choose_Recharge=false;
        if(recharge>0 && initial_power>=enemy_powers[current_circle]){
            Choose_Recharge=CheckPass(current_circle+1, initial_power-enemy_powers[current_circle], skip, recharge-1,enemy_powers, false, initial_power);
        }

        return Choose_Skip || Choose_Recharge;
    }
}

int main(){
    ll initial_power, skip, recharge;
    vector<ll>enemy_powers(11);
    
    cout<<"Enter initial power of Abhimanyu: ";
    cin>>initial_power;
    
    cout<<"Enter number of skip: ";
    cin>>skip;
    
    cout<<"Enter number of recharges: ";
    cin>>recharge;
    
    cout<<"Enter powers of 11 enemies: ";
    for(ll i=0; i<11; i++){
        cin>>enemy_powers[i];
    }
    if(CheckPass(0,initial_power, skip, recharge, enemy_powers, false, initial_power)){
        cout<<" Abhimanyu Pass the Chakrabuhya";
    }
    else{
        cout<<" Abhimanyu Fail the Chakrabuhya";
    }
    return 0;
}