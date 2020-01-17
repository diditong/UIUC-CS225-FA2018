#include<iostream>
#include"bar.h"
#include "foo.h"
using namespace std;

namespace potd{

  bar::bar(string s){
    f_=new foo(s);

  }

  void bar::copy_(const bar& b){
    f_=new foo(b.f_->get_name());
  // f_->count_=b.f->count_;
  // f_->name_=b.f->name_;

  }

  void bar::destroy_(){
    delete f_;
  }

  bar::bar(const bar& b){
   copy_(b);

  }

  bar::~bar(){
    destroy_();
  }


  bar&   bar::operator=(const bar&b){
    destroy_();
    copy_(b);
    return *this;
  }

  string   bar::get_name(){
    return f_->get_name();
  }






}
