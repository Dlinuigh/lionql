#define PROJECT_NAME "lionql"
#include "storage.h"
int main(){
  std::shared_ptr<Space> space_ptr = std::make_shared<Space>();
  Storage storage{space_ptr};
  storage.createDatabase("employees");
  storage.useDatabase("employees");
  storage.createTable("employees_salary", {{"id", "INT", 0, 0}, {"name", "CHAR", 50, 0}, {"birthdate", "DATE", 0, 0}, {"salary","DECIMAL", 5,1}});
  storage.insertData("employees_salary", {{"0", "Jack", "1992-12-10", "12000"}, {"1", "John", "1988-01-08", "13400"}});
  return 0;
}
