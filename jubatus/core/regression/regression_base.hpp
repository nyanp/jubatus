// Jubatus: Online machine learning framework for distributed environment
// Copyright (C) 2012 Preferred Infrastructure and Nippon Telegraph and Telephone Corporation.
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License version 2.1 as published by the Free Software Foundation.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

#ifndef JUBATUS_CORE_REGRESSION_REGRESSION_BASE_HPP_
#define JUBATUS_CORE_REGRESSION_REGRESSION_BASE_HPP_

#include <pficommon/lang/shared_ptr.h>
#include "../common/type.hpp"
#include "../driver/linear_function_mixer.hpp"

namespace jubatus {
namespace core {

namespace storage {
class storage_base;
}  // namespace storage

namespace regression {

class regression_base {
 public:
  typedef pfi::lang::shared_ptr<storage::storage_base> storage_ptr;
  explicit regression_base(storage_ptr storage);

  virtual ~regression_base() {
  }

  virtual void train(const common::sfv_t& fv, const float value) = 0;
  float estimate(const common::sfv_t& fv) const;

  virtual void clear();

  virtual void register_mixables(framework::mixable_holder& holder) const;

  storage::storage_base* get_storage() const {
    return mixable_->get_model().get();
  }

 protected:
  void update(const common::sfv_t& fv, float coeff);

 private:
  pfi::lang::shared_ptr<driver::linear_function_mixer> mixable_;
};

}  // namespace regression

}  // namespace core
}  // namespace jubatus

#endif  // JUBATUS_CORE_REGRESSION_REGRESSION_BASE_HPP_
