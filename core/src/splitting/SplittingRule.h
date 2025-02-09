/*-------------------------------------------------------------------------------
 This file is part of distributional random forest (drf).
 
 drf is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 drf is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with drf. If not, see <http://www.gnu.org/licenses/>.
#-------------------------------------------------------------------------------*/

#ifndef drf_SPLITTINGRULE_H
#define drf_SPLITTINGRULE_H

#include <vector>

#include "commons/Data.h"

namespace drf {

class SplittingRule {
public:
  virtual ~SplittingRule() {}
  virtual bool find_best_split(const Data& data,
                               size_t node,
                               const std::vector<size_t>& possible_split_vars,
                               std::vector<std::vector<double>>& responses_by_sample, // std::vector<double> -> std::vector<std::vector<double>> 
                               const std::vector<std::vector<size_t>>& samples,
                               std::vector<size_t>& split_vars,
                               std::vector<double>& split_values) = 0;
};

} // namespace drf

#endif //drf_SPLITTINGRULE_H


