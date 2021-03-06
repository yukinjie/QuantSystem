/*
 * \copyright Copyright 2015 All Rights Reserved.
 * \license @{
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @}
 */

#ifndef QUANTSYSTEM_INDICATORS_INDICATOR_DATA_POINT_H_
#define QUANTSYSTEM_INDICATORS_INDICATOR_DATA_POINT_H_

#include <glog/logging.h>
#include <string>
using std::string;
#include "quantsystem/common/time/date_time.h"
#include "quantsystem/common/global.h"
#include "quantsystem/common/strings/stringpiece.h"
#include "quantsystem/common/data/subscription_data_config.h"
#include "quantsystem/common/data/base_data.h"
namespace quantsystem {
using data::SubscriptionDataConfig;
using data::BaseData;
namespace indicators {
/**
 * Represents a piece of data at a specific time.
 * @ingroup IndicatorsLayer
 */
class IndicatorDataPoint : public BaseData {
 public:
  IndicatorDataPoint() {
  }

  /**
   * Initializes a new instance of the DataPoint type using
   * the specified time/data.
   */
  IndicatorDataPoint(const DateTime& time, double value);

  /**
   * Standard destructor.
   */
  virtual ~IndicatorDataPoint();

  /**
   * Indicates whether the current object is equal to
   * another object of the same type.
   * @param other An object to compare with this object
   * @return True if the current object is equal to the other, other false.
   */
  bool Equals(const IndicatorDataPoint& other) const;

  /**
   * Returns the hash code for this instance.
   * @return A 32-bit signed integer that is the hash code for this instance..
   */
  virtual int GetHashCode() const;

  /**
   * Convert data source into BaseData objects.
   *
   * Reader converts each line of the data source into BaseData objects.
   * Each data type creates its own factory method,
   * and returns a new instance of the object each time it is called.
   *
   * @param config Subscription data config setup object.
   * @param line Line of the source document.
   * @param date Date of the requested data.
   * @param datafeed Type of datafeed - a live or backtest feed.
   * @return Instance of BaseData object generated by this line of the CSV.
   */
  virtual BaseData* Reader(const SubscriptionDataConfig &config,
                           const StringPiece& line, const DateTime& date,
                             DataFeedEndpoint::Enum datafeed) {
    LOG(ERROR) << "Not implemented";
    return NULL;
  }

  /**
   * Get the URL stirng souce of the file.
   *
   * Return the URL string source of the file.
   * This will be converted to a stream.
   *
   * @param config Configuration object.
   * @param date Date of this souce file.
   * @param data_feed Type of datafeed - a live or backtest feed.
   * @retrurn URL of source file.
   */
  virtual string GetSource(const SubscriptionDataConfig& config,
                           const DateTime& date,
                           DataFeedEndpoint::Enum data_feed) {
    LOG(ERROR) << "Not implemented";
    return "";
  }
};

}  // namespace indicators
}  // namespace quantsystem
#endif  // QUANTSYSTEM_INDICATORS_INDICATOR_DATA_POINT_H_
