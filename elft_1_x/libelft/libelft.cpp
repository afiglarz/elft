/*
 * This software was developed at the National Institute of Standards and
 * Technology (NIST) by employees of the Federal Government in the course
 * of their official duties. Pursuant to title 17 Section 105 of the
 * United States Code, this software is not subject to copyright protection
 * and is in the public domain. NIST assumes no responsibility whatsoever for
 * its use by other parties, and makes no guarantees, expressed or implied,
 * about its quality, reliability, or any other characteristic.
 */

#include <elft.h>

ELFT::ExtractionInterface::ExtractionInterface() = default;
ELFT::ExtractionInterface::~ExtractionInterface() = default;

ELFT::ExtractionInterface::SubmissionIdentification::
    SubmissionIdentification() = default;
ELFT::ExtractionInterface::SubmissionIdentification::SubmissionIdentification(
    const uint16_t versionNumber,
    const std::string &libraryIdentifier,
    const std::optional<ProductIdentifier> &exemplarAlgorithmIdentifier,
    const std::optional<ProductIdentifier> &latentAlgorithmIdentifier) :
    versionNumber{versionNumber},
    libraryIdentifier{libraryIdentifier},
    exemplarAlgorithmIdentifier{exemplarAlgorithmIdentifier},
    latentAlgorithmIdentifier{latentAlgorithmIdentifier}
{

}

ELFT::SearchInterface::SearchInterface() = default;
ELFT::SearchInterface::~SearchInterface() = default;

ELFT::Image::Image() = default;
ELFT::Image::Image(
    const uint8_t identifier,
    const uint16_t width,
    const uint16_t height,
    const uint16_t ppi,
    const uint8_t bpc,
    const uint8_t bpp,
    const std::vector<std::byte> &pixels) :
    identifier{identifier},
    width{width},
    height{height},
    ppi{ppi},
    bpc{bpc},
    bpp{bpp},
    pixels{pixels}
{

}

ELFT::ReturnStatus::operator bool()
    const
    noexcept
{
	return (this->result == Result::Success);
}


ELFT::Candidate::Candidate(
    const std::string &identifier,
    const FrictionRidgeGeneralizedPosition frgp,
    const double similarity) :
    identifier{identifier},
    frgp{frgp},
    similarity{similarity}
{

}

bool
ELFT::Candidate::operator==(
    const Candidate &rhs)
    const
{
	return ((this->similarity == rhs.similarity) &&
	    (this->identifier == rhs.identifier) &&
	    (this->frgp == rhs.frgp));
}

bool
ELFT::Candidate::operator<(
    const Candidate &rhs)
    const
{
	return (this->similarity < rhs.similarity);
}

ELFT::Coordinate::Coordinate(
    const uint32_t x,
    const uint32_t y) :
    x{x},
    y{y}
{

}

bool
ELFT::Coordinate::operator==(
    const Coordinate &rhs)
    const
{
	return ((this->x == rhs.x) && (this->y == rhs.y));
}

bool
ELFT::Coordinate::operator<(
    const Coordinate &rhs)
    const
{
	/* Ascending X */
	if (this->x > rhs.x)
		return (false);
	if (this->x < rhs.x)
		return (true);

	/* Ascending Y */
	if (this->y > rhs.y)
		return (false);
	if (this->y < rhs.y)
		return (true);

	/* Equivalent */
	return (false);

}

ELFT::Correspondence::Correspondence(
    const uint8_t referenceInputIdentifier,
    const Minutia &referenceMinutia,
    const uint8_t probeInputIdentifier,
    const Minutia &probeMinutia) :
    referenceInputIdentifier{referenceInputIdentifier},
    referenceMinutia{referenceMinutia},
    probeInputIdentifier{probeInputIdentifier},
    probeMinutia{probeMinutia}
{

}

ELFT::Minutia::Minutia(
    const Coordinate &coordinate,
    const uint16_t theta,
    const MinutiaType type) :
    coordinate{coordinate},
    theta{theta},
    type{type}
{

}

