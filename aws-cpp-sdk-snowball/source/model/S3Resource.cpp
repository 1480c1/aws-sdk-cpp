/*
* Copyright 2010-2016 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/
#include <aws/snowball/model/S3Resource.h>
#include <aws/core/utils/json/JsonSerializer.h>

#include <utility>

using namespace Aws::Utils::Json;
using namespace Aws::Utils;

namespace Aws
{
namespace Snowball
{
namespace Model
{

S3Resource::S3Resource() : 
    m_bucketArnHasBeenSet(false),
    m_keyRangeHasBeenSet(false)
{
}

S3Resource::S3Resource(const JsonValue& jsonValue) : 
    m_bucketArnHasBeenSet(false),
    m_keyRangeHasBeenSet(false)
{
  *this = jsonValue;
}

S3Resource& S3Resource::operator =(const JsonValue& jsonValue)
{
  if(jsonValue.ValueExists("BucketArn"))
  {
    m_bucketArn = jsonValue.GetString("BucketArn");

    m_bucketArnHasBeenSet = true;
  }

  if(jsonValue.ValueExists("KeyRange"))
  {
    m_keyRange = jsonValue.GetObject("KeyRange");

    m_keyRangeHasBeenSet = true;
  }

  return *this;
}

JsonValue S3Resource::Jsonize() const
{
  JsonValue payload;

  if(m_bucketArnHasBeenSet)
  {
   payload.WithString("BucketArn", m_bucketArn);

  }

  if(m_keyRangeHasBeenSet)
  {
   payload.WithObject("KeyRange", m_keyRange.Jsonize());

  }

  return payload;
}

} // namespace Model
} // namespace Snowball
} // namespace Aws