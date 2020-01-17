
vector<string> NoProblem(int start, vector<int> created, vector<int> needed) {
    vector<string> result;
    int store = start;
    std::vector<int>::iterator it;

  it = created.begin();
  it = created.insert ( it , 0);
   for(int i = 0; i < 12; i++){
     if(created[i]+store<needed[i]){
     result.push_back("No problem. :(");
     store+=created[i];
   }
     else{
     result.push_back("No problem! :D");
     store-=needed[i];
     store+=created[i];
     }

   }
   return result;
}
