#include "food.h"
namespace cs225 {
  food::food() {
    quantity_ = 5;
    name_ = "apples";
  }
  string
  food::get_name() {
    return name_;
  }
  int
  food::get_quantity() {
    return quantity_;
  }
  void
  food::set_quantity(int quantity) {
    quantity_ = quantity;
  }
  void food::set_name(string name) {
    name_ = name;
  }
}
