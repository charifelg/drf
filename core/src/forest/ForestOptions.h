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

#ifndef DRF_FORESTOPTIONS_H
#define DRF_FORESTOPTIONS_H


#include "commons/globals.h"
#include "sampling/SamplingOptions.h"
#include "tree/TreeOptions.h"

namespace drf {

class ForestOptions {
public:
  ForestOptions(uint num_trees,
                size_t ci_group_size,
                double sample_fraction,
                uint mtry,
                uint min_node_size,
                bool honesty,
                double honesty_fraction,
                bool honesty_prune_leaves,
                double alpha,
                double imbalance_penalty,
                uint num_threads,
                uint random_seed,
                const std::vector<size_t>& sample_clusters,
                uint samples_per_cluster,
                size_t num_features,
                double bandwidth,
                unsigned int node_scaling);

  static uint validate_num_threads(uint num_threads);

  uint get_num_trees() const;
  size_t get_ci_group_size() const;
  double get_sample_fraction() const;

  const TreeOptions& get_tree_options() const;
  const SamplingOptions& get_sampling_options() const;

  uint get_num_threads() const;
  uint get_random_seed() const;
  

private:
  uint num_trees;
  size_t ci_group_size;
  double sample_fraction;

  TreeOptions tree_options;
  SamplingOptions sampling_options;

  uint num_threads;
  uint random_seed;

};

} // namespace drf

#endif //DRF_FORESTOPTIONS_H
