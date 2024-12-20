/* Copyright 2024 The OpenXLA Authors.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifndef XLA_BACKENDS_GPU_COLLECTIVES_NCCL_COLLECTIVES_H_
#define XLA_BACKENDS_GPU_COLLECTIVES_NCCL_COLLECTIVES_H_

#include "absl/status/statusor.h"
#include "xla/backends/gpu/collectives/gpu_collectives.h"
#include "xla/core/collectives/clique_id.h"
#include "xla/service/gpu/runtime/nccl_api.h"

namespace xla::gpu {

// XLA host-initiated collectives implemented on top of NCCL.
//
// TODO(ezhulenev): Instead of NcclApi, we should inherit from GpuCollectives.
class NcclCollectives : public NcclApi {
 public:
  // Returns true if the collectives backend uses.
  bool IsGlobalConfig() const final;

  absl::StatusOr<const CliqueIdCallback*> GetCliqueIdCallback(
      const CliqueIdCallback* clique_id_callback, bool is_local) final;

  absl::StatusOr<CliqueId> CreateUniqueCliqueId() const final;
};

}  // namespace xla::gpu

#endif  // XLA_BACKENDS_GPU_COLLECTIVES_NCCL_COLLECTIVES_H_
