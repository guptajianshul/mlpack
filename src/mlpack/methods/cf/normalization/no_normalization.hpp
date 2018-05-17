/**
 * @file no_normalization.hpp
 * @author Wenhao Huang
 *
 * This class performs no normalization. It is used as default type of
 * normalization for CF class.
 *
 * mlpack is free software; you may redistribute it and/or modify it under the
 * terms of the 3-clause BSD license.  You should have received a copy of the
 * 3-clause BSD license along with mlpack.  If not, see
 * http://www.opensource.org/licenses/BSD-3-Clause for more information.
 */
#ifndef MLPACK_METHODS_CF_NORMALIZATION_NO_NORMALIZATION_HPP
#define MLPACK_METHODS_CF_NORMALIZATION_NO_NORMALIZATION_HPP

#include <mlpack/prereqs.hpp>

namespace mlpack {
namespace cf {

/**
 * This normalization class doesn't perform any normalization. It is the default
 * normalization type for CF class.
 */
class NoNormalization
{
 public:
  // Empty constructor.
  NoNormalization() { }

  /**
   * Do nothing.
   *
   * @param data Input dataset in the form of coordinate list.
   */
  inline void Normalize(const arma::mat& /* data */) const { }

  /**
   * Do nothing.
   *
   * @param cleanedData Sparse matrix data.
   */
  inline void Normalize(const arma::sp_mat& /* cleanedData */) const { }

  /**
   * Do nothing.
   *
   * @param user User ID.
   * @param item Item ID.
   * @param rating Computed rating before denormalization.
   */
  inline double Denormalize(const int /* user */,
                   const int /* item */,
                   const double rating) const
  {
    return rating;
  }

  /**
   * Do nothing.
   *
   * @param combinations User/Item combinations.
   * @param predictions Predicted Ratings for each User/Item combination.
   */
  inline void Denormalize(const arma::Mat<size_t>& /* combinations */,
                 const arma::vec& /* predictions */) const
  { }

  /**
   * Serialization.
   */
  template<typename Archive>
  void serialize(Archive& /* ar */, const unsigned int /* version */) { }
};

} // namespace cf
} // namespace mlpack

#endif
