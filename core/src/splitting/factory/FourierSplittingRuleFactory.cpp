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

#include "splitting/factory/FourierSplittingRuleFactory.h"
#include "splitting/FourierSplittingRule.h"

namespace drf {

std::unique_ptr<SplittingRule> FourierSplittingRuleFactory::create(const Data& data,
                                                                      const TreeOptions& options) const {
  return std::unique_ptr<SplittingRule>(new FourierSplittingRule(
      data.get_max_num_unique_values(),
      options.get_alpha(),
      options.get_imbalance_penalty(),
      data.get_outcome_index().size(),
      options.get_num_features(),
      options.get_bandwidth(),
      options.get_node_scaling()));
}

} // namespace drf
