/* Copyright (c) 2016 PaddlePaddle Authors. All Rights Reserve.

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

   http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License. */

#include <iostream>
#include "paddle/framework/op_registry.h"

namespace paddle {
namespace framework {
class FCOp : public OperatorBase {
 public:
  void Run(const ScopePtr& scope,
           const platform::DeviceContext& dev_ctx) const override {
    std::cout << "FC" << std::endl;
  };
  void InferShape(const ScopePtr& scope) const override{};
};

class FCOpProtoAndCheckerMaker : public OpProtoAndCheckerMaker {
 public:
  FCOpProtoAndCheckerMaker(OpProto* proto, OpAttrChecker* op_checker)
      : OpProtoAndCheckerMaker(proto, op_checker) {
    AddInput("x", "input data");
    AddInput("w", "weights");
    AddInput("b", "bias");
    AddOutput("y", "output data");
    AddComment("Fully connnect op");
  }
};

class FCGradientOp : public OperatorBase {
  void Run(const ScopePtr& scope,
           const platform::DeviceContext& dev_ctx) const override {
    std::cout << "FCGrad" << std::endl;
  };
  void InferShape(const ScopePtr& scope) const override{};
};

// class FCGradientOpProtoAndCheckerMaker : public OpProtoAndCheckerMaker {};

}  // namespace framework
}  // namespace paddle
