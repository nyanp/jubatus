// Jubatus: Online machine learning framework for distributed environment
// Copyright (C) 2013 Preferred Infrastructure and Nippon Telegraph and Telephone Corporation.
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

#ifndef JUBATUS_CORE_CLUSTERING_KMEANS_COMPRESSOR_HPP_
#define JUBATUS_CORE_CLUSTERING_KMEANS_COMPRESSOR_HPP_

#include "compressor.hpp"

namespace jubatus {
namespace core {
namespace clustering {
namespace compressor {

class kmeans_compressor : public compressor {
 public:
  explicit kmeans_compressor(const clustering_config& cfg);
  ~kmeans_compressor();

  void compress(const wplist& src, size_t bsize, size_t dstsize, wplist& dst);

 public:
  virtual double get_probability(
      const weighted_point& p,
      double min_dist,
      const weighted_point& nearest_bp,
      double bp_score,
      double weight_sum,
      double squared_min_dist_sum);

 private:
  void get_bicriteria(
      const wplist& src,
      size_t bsize,
      size_t dstsize,
      wplist& dst);

  void bicriteria_to_coreset(
      const wplist& src,
      const wplist& bicriteria,
      size_t dstsize,
      wplist& dst);
};

}  // namespace compressor
}  // namespace clustering
}  // namespace core
}  // namespace jubatus

#endif  // JUBATUS_CORE_CLUSTERING_KMEANS_COMPRESSOR_HPP_
