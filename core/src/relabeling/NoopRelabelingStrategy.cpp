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

#include "relabeling/NoopRelabelingStrategy.h"

namespace drf {

bool NoopRelabelingStrategy::relabel(
    const std::vector<size_t>& samples,
    const Data& data,
    std::vector<std::vector<double>>& responses_by_sample) const { // std::vector<double> -> std::vector<std::vector<double>> 

  for (size_t sample : samples) {
  //  std::cout << data.get_outcome(sample) << std::endl;
    //std::vector<double> outcome(2,0.0);
 //  std::cout << outcome.size() << std::endl;
    std::vector<double> outcome = data.get_outcome(sample);
   // std::vector<double> outcome;
   // outcome.resize(2);
   // for (size_t d = 0; )
    
   // std::cout << "outcome size" << std::endl;
   // std::cout << (outcome).size() << std::endl;
   // std::cout << "outcome first value at sample" << std::endl;
  //  std::cout << (outcome)[0] << std::endl;
   // std::cout << "outcome second value at sample" << std::endl;
   // std::cout << (outcome)[1] << std::endl;
   // std::cout << "outcome size" << std::endl;
   // std::cout << data.get_outcome(sample).size() << std::endl;
  //  std::cout << outcome.size() << std::endl;
    responses_by_sample[sample] = outcome;
  }
  return false;
}

} // namespace drf

