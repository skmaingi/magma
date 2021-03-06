/*
 * Licensed to the OpenAirInterface (OAI) Software Alliance under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The OpenAirInterface Software Alliance licenses this file to You under
 * the Apache License, Version 2.0  (the "License"); you may not use this file
 * except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *-------------------------------------------------------------------------------
 * For more information about the OpenAirInterface (OAI) Software Alliance:
 *      contact@openairinterface.org
 */
#pragma once

#include <grpc++/grpc++.h>
#include "feg/protos/s6a_proxy.grpc.pb.h"

using grpc::ServerContext;
using grpc::Status;

namespace magma {
using namespace feg;
class S6aProxyImpl final : public S6aGatewayService::Service {
 public:
  S6aProxyImpl();

  /*
       * Cancel Location Request
       * S6a Command Code: 317
       *
       * @param context: the grpc Server context
       * @param request: CancelLocationRequest
       * @param response (out): CancelLocationAnswer
       * @return grpc Status instance
       */
  Status CancelLocation(
    ServerContext *context,
    const CancelLocationRequest *request,
    CancelLocationAnswer *response) override;
  /*
       * Reset Request
       * S6a Command Code: 322
       *
       * @param context: the grpc Server context
       * @param request: ResetRequest
       * @param response (out): ResetAnswer
       * @return grpc Status instance
       */
  Status Reset(
    ServerContext *context,
    const ResetRequest *request,
    ResetAnswer *response) override;
};

} // namespace magma
