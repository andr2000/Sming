/****
 * Sming Framework Project - Open Source framework for high efficiency native ESP8266 development.
 * Created 2015 by Skurydin Alexey
 * http://github.com/SmingHub/Sming
 * All files of the Sming Core are provided under the LGPL v3 license.
 *
 * @author Slavey Karadzhov <slaff@attachix.com>
 *
 ****/

#ifndef _SMING_CORE_DATA_URL_ENCODDED_OUTPUT_STREAM_H_
#define _SMING_CORE_DATA_URL_ENCODDED_OUTPUT_STREAM_H_

#include "MemoryDataStream.h"
#include "Network/Http/HttpParams.h"

/**
 * @brief      UrlEncoded Stream
 * @ingroup    stream data
 *
 *  @{
 */

class UrlencodedOutputStream : public IDataSourceStream
{
public:
	/**
	 * @brief Represents key-value pairs as urlencoded string
	 * @param params The key-value parameters
	 */
	UrlencodedOutputStream(const HttpParams& params);

	virtual ~UrlencodedOutputStream()
	{
	}

	//Use base class documentation
	virtual StreamType getStreamType() const
	{
		return stream.getStreamType();
	}

	/**
	 * @brief Return the total length of the stream
	 * @retval int -1 is returned when the size cannot be determined
	 */
	int available()
	{
		return stream.available();
	}

	//Use base class documentation
	virtual uint16_t readMemoryBlock(char* data, int bufSize)
	{
		return stream.readMemoryBlock(data, bufSize);
	}

	//Use base class documentation
	virtual bool seek(int len)
	{
		return stream.seek(len);
	}

	//Use base class documentation
	virtual bool isFinished()
	{
		return stream.isFinished();
	}

private:
	MemoryDataStream stream;
};

/** @} */
#endif /* _SMING_CORE_DATA_URL_ENCODDED_OUTPUT_STREAM_H_ */
