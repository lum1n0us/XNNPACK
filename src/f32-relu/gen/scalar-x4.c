// Auto-generated file. Do not edit!
//   Template: src/f32-relu/scalar.c.in
//   Generator: tools/xngen
//
// Copyright 2020 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <xnnpack/vunary.h>
#include <xnnpack/common.h>
#include <xnnpack/math.h>

void xnn_f32_relu_ukernel__scalar_x4(
    size_t n,
    const float* x_ptr,
    float* y_ptr,
    const union xnn_f32_relu_params params[restrict XNN_MIN_ELEMENTS(1)])
{
  assert(n != 0);
  assert(n % sizeof(float) == 0);
  assert(x_ptr != NULL);
  assert(y_ptr != NULL);

  const uint32_t* x = (const uint32_t*)x_ptr;
  uint32_t* y = (uint32_t*)y_ptr;

  for (; n >= 4 * sizeof(uint32_t); n -= 4 * sizeof(uint32_t)) {
    uint32_t vacc0 = x[0];
    uint32_t vacc1 = x[1];
    uint32_t vacc2 = x[2];
    uint32_t vacc3 = x[3];
    x += 4;

    vacc0 = ((vacc0 >> 31) - 1) & vacc0;
    vacc1 = ((vacc1 >> 31) - 1) & vacc1;
    vacc2 = ((vacc2 >> 31) - 1) & vacc2;
    vacc3 = ((vacc3 >> 31) - 1) & vacc3;

    y[0] = vacc0;
    y[1] = vacc1;
    y[2] = vacc2;
    y[3] = vacc3;
    y += 4;
  }
  if XNN_UNLIKELY(n != 0) {
    do {
      uint32_t vacc = *x++;
      vacc =  ((vacc >> 31) - 1) & vacc;
      *y++ = vacc;
      n -= sizeof(uint32_t);
    } while (n != 0);
  }
}
