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

#ifndef drf_OPTIMIZEDPREDICTIONCOLLECTOR_H
#define drf_OPTIMIZEDPREDICTIONCOLLECTOR_H


#include "forest/Forest.h"
#include "prediction/collector/PredictionCollector.h"

namespace drf {

class OptimizedPredictionCollector final: public PredictionCollector {
public:
  OptimizedPredictionCollector(std::unique_ptr<OptimizedPredictionStrategy> strategy, uint num_threads);

  std::vector<Prediction> collect_predictions(const Forest& forest,
                                              const Data& train_data,
                                              const Data& data,
                                              const std::vector<std::vector<size_t>>& leaf_nodes_by_tree,
                                              const std::vector<std::vector<bool>>& valid_trees_by_sample,
                                              bool estimate_variance,
                                              bool estimate_error) const;

private:
  std::vector<Prediction> collect_predictions_batch(const Forest& forest,
                                                    const Data& train_data,
                                                    const Data& data,
                                                    const std::vector<std::vector<size_t>>& leaf_nodes_by_tree,
                                                    const std::vector<std::vector<bool>>& valid_trees_by_sample,
                                                    bool estimate_variance,
                                                    bool estimate_error,
                                                    size_t start,
                                                    size_t num_samples) const;

  void add_prediction_values(size_t node,
                             const PredictionValues& prediction_values,
                             std::vector<double>& combined_average) const; // std::vector<double>& -> std::vector<std::vector<double>>&

  void normalize_prediction_values(size_t num_leaves,
                                   std::vector<double>& combined_average) const; // std::vector<double>& -> std::vector<std::vector<double>>&

  void validate_prediction(size_t sample,
                           const Prediction& prediction) const;

  std::unique_ptr<OptimizedPredictionStrategy> strategy;
  uint num_threads;
};

} // namespace drf

#endif //drf_OPTIMIZEDPREDICTIONCOLLECTOR_H
