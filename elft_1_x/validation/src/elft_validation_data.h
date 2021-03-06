/*
 * This software was developed at the National Institute of Standards and
 * Technology (NIST) by employees of the Federal Government in the course
 * of their official duties. Pursuant to title 17 Section 105 of the
 * United States Code, this software is not subject to copyright protection
 * and is in the public domain. NIST assumes no responsibility whatsoever for
 * its use by other parties, and makes no guarantees, expressed or implied,
 * about its quality, reliability, or any other characteristic.
 */

#ifndef ELFT_VALIDATION_DATA_H_
#define ELFT_VALIDATION_DATA_H_

#include <filesystem>
#include <map>
#include <string>

#include <elft.h>

namespace ELFT::Validation::Data
{
	/** Directory within output directory to contain templates */
	const std::filesystem::path TemplateDir{"templates"};
	/** Directory containing generated latent templates. */
	const std::filesystem::path LatentTemplateDir{TemplateDir / "latent"};
	/** Directory containing generated reference templates. */
	const std::filesystem::path ReferenceTemplateDir{TemplateDir /
	    "reference"};
	/** Suffix added to template files. */
	const std::string TemplateSuffix{".tmpl"};

	const std::filesystem::path&
	getTemplateDir(
	    TemplateType type)
	{
		switch (type) {
		case TemplateType::Probe:
			return (LatentTemplateDir);
		case TemplateType::Reference:
			return (ReferenceTemplateDir);
		default:
			throw std::runtime_error{"Unknown TemplateType sent to "
			    "Data::getTemplateDir()"};
		}
	}

	/** Information about a validation image. */
	struct ImageMetadata
	{
		/** Name of the file within image directory. */
		std::optional<std::string> filename{};
		/** Width of the image. */
		std::optional<uint16_t> width{};
		/** Height of the image. */
		std::optional<uint16_t> height{};
		/** Resolution of the image in pixels per inch. */
		std::optional<uint16_t> ppi{};
		/** Number of bits used by each color component (8 or 16). */
		std::optional<uint8_t> bpc{};
		/** Number of bits comprising a single pixel. */
		std::optional<uint8_t> bpp{};
		/** EFS data. */
		std::optional<EFS> efs{};
	};

	/** Convenience type definition for hard-coded image info. */
	using ImageSet = std::pair<std::string, std::vector<ImageMetadata>>;

	/** Latent images to be made into templates. */
	const std::vector<ImageSet> Latents {
	    {"00002357_2B_X_L01_BP_S24_1200PPI_8BPC_1CH_LP02_1_1207x1131", {
	        {"00002357_2B_X_L01_BP_S24_1200PPI_8BPC_1CH_LP02_1_1207x1131"
	         ".gray", 1207, 1131, 1200, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_1G_L_L01_BP_S24_1200PPI_8BPC_1CH_LP04_1_978x889", {
	        {"00002357_1G_L_L01_BP_S24_1200PPI_8BPC_1CH_LP04_1_978x889"
	         ".gray", 978, 889, 1200, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_3_X_0239_IN_D800_1000PPI_8BPC_1CH_LP07_1_724x1080", {
	        {"00002357_3_X_0239_IN_D800_1000PPI_8BPC_1CH_LP07_1_724x1080"
	         ".gray", 724, 1080, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::Indanedione,
	                ProcessingMethod::Laser
	            }
	        }
	    }}},

	    {"00002357_3_X_0233_IN_D800_1044PPI_16BPC_1CH_LP03_1_1303x966", {
	        {"00002357_3_X_0233_IN_D800_1044PPI_16BPC_1CH_LP03_1_1303x966"
	         ".gray", 1303, 966, 1044, 16, 16, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::Indanedione,
	                ProcessingMethod::Laser
	            }
	        }
	    }}},

	    {"00002357_3_X_0232_IN_D800_1044PPI_16BPC_1CH_LP16_1_930x1044", {
	        {"00002357_3_X_0232_IN_D800_1044PPI_16BPC_1CH_LP16_1_930x1044"
	         ".gray", 930, 1044, 1044, 16, 16, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::Indanedione,
	                ProcessingMethod::Laser
	            }
	        }
	    }}},

	    {"00002357_1H_L_L01_BP_S24_1000PPI_8BPC_1CH_LP15_1_561x699", {
	        {"00002357_1H_L_L01_BP_S24_1000PPI_8BPC_1CH_LP15_1_561x699"
	         ".gray", 561, 699, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_3_X_0230_IN_D800_1000PPI_8BPC_1CH_LP07_1_883x965", {
	        {"00002357_3_X_0230_IN_D800_1000PPI_8BPC_1CH_LP07_1_883x965"
	         ".gray", 883, 965, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::Indanedione,
	                ProcessingMethod::Laser
	            }
	        }
	    }}},

	    {"00002357_1H_R_L01_BP_S24_1000PPI_8BPC_1CH_LP07_1_572x478", {
	        {"00002357_1H_R_L01_BP_S24_1000PPI_8BPC_1CH_LP07_1_572x478"
	         ".gray", 572, 478, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_6D_X_110_WT_D800_1109PPI_16BPC_1CH_LP01_1_798x624", {
	        {"00002357_6D_X_110_WT_D800_1109PPI_16BPC_1CH_LP01_1_798x624"
	         ".gray", 798, 624, 1109, 16, 16, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::StickysidePowder
	            }
	        }
	    }}},

	    {"00002357_1H_L_L01_BP_S24_1200PPI_8BPC_1CH_LP12_1_625x669", {
	        {"00002357_1H_L_L01_BP_S24_1200PPI_8BPC_1CH_LP12_1_625x669"
	         ".gray", 625, 669, 1200, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_2B_X_L02_BP_S24_1000PPI_8BPC_1CH_LP05_1_649x812", {
	        {"00002357_2B_X_L02_BP_S24_1000PPI_8BPC_1CH_LP05_1_649x812"
	         ".gray", 649, 812, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_1D_R_L01_BP_S24_1000PPI_8BPC_1CH_LP03_1_742x1087", {
	        {"00002357_1D_R_L01_BP_S24_1000PPI_8BPC_1CH_LP03_1_742x1087"
	         ".gray", 742, 1087, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_3_X_0240_IN_D800_1044PPI_16BPC_1CH_LP10_1_582x627", {
	        {"00002357_3_X_0240_IN_D800_1044PPI_16BPC_1CH_LP10_1_582x627"
	         ".gray", 582, 627, 1044, 16, 16, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::Indanedione,
	                ProcessingMethod::Laser
	            }
	        }
	    }}},

	    {"00002357_1H_R_L01_BP_S24_1200PPI_8BPC_1CH_LP02_1_678x575", {
	        {"00002357_1H_R_L01_BP_S24_1200PPI_8BPC_1CH_LP02_1_678x575"
	         ".gray", 678, 575, 1200, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_1G_L_L01_BP_S24_1000PPI_8BPC_1CH_LP04_1_815x741", {
	        {"00002357_1G_L_L01_BP_S24_1000PPI_8BPC_1CH_LP04_1_815x741"
	         ".gray", 815, 741, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_1G_R_L01_BP_S24_1200PPI_8BPC_1CH_LP04_1_1097x976", {
	        {"00002357_1G_R_L01_BP_S24_1200PPI_8BPC_1CH_LP04_1_1097x976"
	         ".gray", 1097, 976, 1200, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_1H_R_L01_BP_S24_1200PPI_8BPC_1CH_LP07_1_686x574", {
	        {"00002357_1H_R_L01_BP_S24_1200PPI_8BPC_1CH_LP07_1_686x574"
	         ".gray", 686, 574, 1200, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_2B_X_L01_BP_S24_1000PPI_8BPC_1CH_LP02_1_1006x942", {
	        {"00002357_2B_X_L01_BP_S24_1000PPI_8BPC_1CH_LP02_1_1006x942"
	         ".gray", 1006, 942, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_6D_X_110_WT_D800_1000PPI_8BPC_1CH_LP03_1_771x579", {
	        {"00002357_6D_X_110_WT_D800_1000PPI_8BPC_1CH_LP03_1_771x579"
	         ".gray", 771, 579, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::StickysidePowder
	            }
	        }
	    }}},

	    {"00002357_2B_X_L02_BP_S24_1000PPI_8BPC_1CH_LP06_1_899x699", {
	        {"00002357_2B_X_L02_BP_S24_1000PPI_8BPC_1CH_LP06_1_899x699"
	         ".gray", 899, 699, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_6A_X_210_BT_D800_1000PPI_8BPC_1CH_LP01_1_405x587", {
	        {"00002357_6A_X_210_BT_D800_1000PPI_8BPC_1CH_LP01_1_405x587"
	         ".gray", 405, 587, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::StickysidePowder
	            }
	        }
	    }}},

	    {"00002357_1C_R_L01_BP_S24_1200PPI_8BPC_1CH_LP02_1_882x1003", {
	        {"00002357_1C_R_L01_BP_S24_1200PPI_8BPC_1CH_LP02_1_882x1003"
	         ".gray", 882, 1003, 1200, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_5A_X_028_IN_D800_1109PPI_16BPC_1CH_LP03_1_1102x723", {
	        {"00002357_5A_X_028_IN_D800_1109PPI_16BPC_1CH_LP03_1_1102x723"
	         ".gray", 1102, 723, 1109, 16, 16, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::Indanedione,
	                ProcessingMethod::Laser
	            }
	        }
	    }}},

	    {"00002357_1H_L_L01_BP_S24_1200PPI_8BPC_1CH_LP13_1_662x688", {
	        {"00002357_1H_L_L01_BP_S24_1200PPI_8BPC_1CH_LP13_1_662x688"
	         ".gray", 662, 688, 1200, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_6D_X_110_WT_D800_1109PPI_16BPC_1CH_LP04_1_855x408", {
	        {"00002357_6D_X_110_WT_D800_1109PPI_16BPC_1CH_LP04_1_855x408"
	         ".gray", 855, 408, 1109, 16, 16, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::StickysidePowder
	            }
	        }
	    }}},

	    {"00002357_3_X_0239_IN_D800_1044PPI_16BPC_1CH_LP07_1_756x1128", {
	        {"00002357_3_X_0239_IN_D800_1044PPI_16BPC_1CH_LP07_1_756x1128"
	         ".gray", 756, 1128, 1044, 16, 16, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::Indanedione,
	                ProcessingMethod::Laser
	            }
	        }
	    }}},

	    {"00002357_1H_L_L01_BP_S24_1000PPI_8BPC_1CH_LP12_1_521x557", {
	        {"00002357_1H_L_L01_BP_S24_1000PPI_8BPC_1CH_LP12_1_521x557"
	         ".gray", 521, 557, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_5A_X_027_IN_D800_1000PPI_8BPC_1CH_LP05_1_615x622", {
	        {"00002357_5A_X_027_IN_D800_1000PPI_8BPC_1CH_LP05_1_615x622"
	         ".gray", 615, 622, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::Indanedione,
	                ProcessingMethod::Laser
	            }
	        }
	    }}},

	    {"00002357_5A_X_027_IN_D800_1000PPI_8BPC_1CH_LP02_1_824x750", {
	        {"00002357_5A_X_027_IN_D800_1000PPI_8BPC_1CH_LP02_1_824x750"
	         ".gray", 824, 750, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::Indanedione,
	                ProcessingMethod::Laser
	            }
	        }
	    }}},

	    {"00002357_6D_X_110_WT_D800_1000PPI_8BPC_1CH_LP04_1_771x368", {
	        {"00002357_6D_X_110_WT_D800_1000PPI_8BPC_1CH_LP04_1_771x368"
	         ".gray", 771, 368, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::StickysidePowder
	            }
	        }
	    }}},

	    {"00002357_1E_L_L01_BP_S24_1200PPI_8BPC_1CH_LP02_1_792x1177", {
	        {"00002357_1E_L_L01_BP_S24_1200PPI_8BPC_1CH_LP02_1_792x1177"
	         ".gray", 792, 1177, 1200, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_1H_L_L01_BP_S24_1000PPI_8BPC_1CH_LP11_1_494x474", {
	        {"00002357_1H_L_L01_BP_S24_1000PPI_8BPC_1CH_LP11_1_494x474"
	         ".gray", 494, 474, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_3_X_0240_IN_D800_1000PPI_8BPC_1CH_LP10_1_557x601", {
	        {"00002357_3_X_0240_IN_D800_1000PPI_8BPC_1CH_LP10_1_557x601"
	         ".gray", 557, 601, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::Indanedione,
	                ProcessingMethod::Laser
	            }
	        }
	    }}},

	    {"00002357_3_X_0233_IN_D800_1000PPI_8BPC_1CH_LP03_1_1248x925", {
	        {"00002357_3_X_0233_IN_D800_1000PPI_8BPC_1CH_LP03_1_1248x925"
	         ".gray", 1248, 925, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::Indanedione,
	                ProcessingMethod::Laser
	            }
	        }
	    }}},

	    {"00002357_1G_R_L01_BP_S24_1200PPI_8BPC_1CH_LP05_1_1008x839", {
	        {"00002357_1G_R_L01_BP_S24_1200PPI_8BPC_1CH_LP05_1_1008x839"
	         ".gray", 1008, 839, 1200, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_5A_X_028_IN_D800_1000PPI_8BPC_1CH_LP01_1_907x713", {
	        {"00002357_5A_X_028_IN_D800_1000PPI_8BPC_1CH_LP01_1_907x713"
	         ".gray", 907, 713, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::Indanedione,
	                ProcessingMethod::Laser
	            }
	        }
	    }}},

	    {"00002357_1H_R_L01_BP_S24_1000PPI_8BPC_1CH_LP08_1_533x565", {
	        {"00002357_1H_R_L01_BP_S24_1000PPI_8BPC_1CH_LP08_1_533x565"
	         ".gray", 533, 565, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_1H_L_L01_BP_S24_1000PPI_8BPC_1CH_LP13_1_552x573", {
	        {"00002357_1H_L_L01_BP_S24_1000PPI_8BPC_1CH_LP13_1_552x573"
	         ".gray", 552, 573, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_3_X_0230_IN_D800_1000PPI_8BPC_1CH_LP02_1_389x643", {
	        {"00002357_3_X_0230_IN_D800_1000PPI_8BPC_1CH_LP02_1_389x643"
	         ".gray", 389, 643, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::Indanedione,
	                ProcessingMethod::Laser
	            }
	        }
	    }}},

	    {"00002357_3_X_0239_IN_D800_1044PPI_16BPC_1CH_LP01_1_780x1153", {
	        {"00002357_3_X_0239_IN_D800_1044PPI_16BPC_1CH_LP01_1_780x1153"
	         ".gray", 780, 1153, 1044, 16, 16, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::Indanedione,
	                ProcessingMethod::Laser
	            }
	        }
	    }}},

	    {"00002357_1H_L_L01_BP_S24_1200PPI_8BPC_1CH_LP11_1_593x569", {
	        {"00002357_1H_L_L01_BP_S24_1200PPI_8BPC_1CH_LP11_1_593x569"
	         ".gray", 593, 569, 1200, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_1H_R_L01_BP_S24_1000PPI_8BPC_1CH_LP15_1_677x872", {
	        {"00002357_1H_R_L01_BP_S24_1000PPI_8BPC_1CH_LP15_1_677x872"
	         ".gray", 677, 872, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_2B_X_L01_BP_S24_1200PPI_8BPC_1CH_LP10_1_1089x1169", {
	        {"00002357_2B_X_L01_BP_S24_1200PPI_8BPC_1CH_LP10_1_1089x1169"
	         ".gray", 1089, 1169, 1200, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_1D_L_L01_BP_S24_1200PPI_8BPC_1CH_LP05_1_856x1513", {
	        {"00002357_1D_L_L01_BP_S24_1200PPI_8BPC_1CH_LP05_1_856x1513"
	         ".gray", 856, 1513, 1200, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_3_X_0232_IN_D800_1000PPI_8BPC_1CH_LP16_1_891x1000", {
	        {"00002357_3_X_0232_IN_D800_1000PPI_8BPC_1CH_LP16_1_891x1000"
	         ".gray", 891, 1000, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::Indanedione,
	                ProcessingMethod::Laser
	            }
	        }
	    }}},

	    {"00002357_1H_L_L01_BP_S24_1000PPI_8BPC_1CH_LP04_1_464x607", {
	        {"00002357_1H_L_L01_BP_S24_1000PPI_8BPC_1CH_LP04_1_464x607"
	         ".gray", 464, 607, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_1H_R_L01_BP_S24_1000PPI_8BPC_1CH_LP02_1_565x479", {
	        {"00002357_1H_R_L01_BP_S24_1000PPI_8BPC_1CH_LP02_1_565x479"
	         ".gray", 565, 479, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_6D_X_110_WT_D800_1109PPI_16BPC_1CH_LP03_1_855x642", {
	        {"00002357_6D_X_110_WT_D800_1109PPI_16BPC_1CH_LP03_1_855x642"
	         ".gray", 855, 642, 1109, 16, 16, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::StickysidePowder
	            }
	        }
	    }}},

	    {"00002357_5A_X_027_IN_D800_1109PPI_16BPC_1CH_LP05_1_682x690", {
	        {"00002357_5A_X_027_IN_D800_1109PPI_16BPC_1CH_LP05_1_682x690"
	         ".gray", 682, 690, 1109, 16, 16, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::Indanedione,
	                ProcessingMethod::Laser
	            }
	        }
	    }}},

	    {"00002357_5A_X_027_IN_D800_1109PPI_16BPC_1CH_LP06_1_669x876", {
	        {"00002357_5A_X_027_IN_D800_1109PPI_16BPC_1CH_LP06_1_669x876"
	         ".gray", 669, 876, 1109, 16, 16, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::Indanedione,
	                ProcessingMethod::Laser
	            }
	        }
	    }}},

	    {"00002357_1D_L_L01_BP_S24_1200PPI_8BPC_1CH_LP03_1_757x1104", {
	        {"00002357_1D_L_L01_BP_S24_1200PPI_8BPC_1CH_LP03_1_757x1104"
	         ".gray", 757, 1104, 1200, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_6D_X_110_WT_D800_1109PPI_16BPC_1CH_LP08_1_431x381", {
	        {"00002357_6D_X_110_WT_D800_1109PPI_16BPC_1CH_LP08_1_431x381"
	         ".gray", 431, 381, 1109, 16, 16, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::StickysidePowder
	            }
	        }
	    }}},

	    {"00002357_1C_R_L01_BP_S24_1000PPI_8BPC_1CH_LP02_1_735x836", {
	        {"00002357_1C_R_L01_BP_S24_1000PPI_8BPC_1CH_LP02_1_735x836"
	         ".gray", 735, 836, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_1E_L_L01_BP_S24_1000PPI_8BPC_1CH_LP02_1_660x981", {
	        {"00002357_1E_L_L01_BP_S24_1000PPI_8BPC_1CH_LP02_1_660x981"
	         ".gray", 660, 981, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_1H_R_L01_BP_S24_1200PPI_8BPC_1CH_LP08_1_640x678", {
	        {"00002357_1H_R_L01_BP_S24_1200PPI_8BPC_1CH_LP08_1_640x678"
	         ".gray", 640, 678, 1200, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_3_X_0239_IN_D800_1000PPI_8BPC_1CH_LP01_1_747x1104", {
	        {"00002357_3_X_0239_IN_D800_1000PPI_8BPC_1CH_LP01_1_747x1104"
	         ".gray", 747, 1104, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::Indanedione,
	                ProcessingMethod::Laser
	            }
	        }
	    }}},

	    {"00002357_5A_X_027_IN_D800_1000PPI_8BPC_1CH_LP06_1_603x790", {
	        {"00002357_5A_X_027_IN_D800_1000PPI_8BPC_1CH_LP06_1_603x790"
	         ".gray", 603, 790, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::Indanedione,
	                ProcessingMethod::Laser
	            }
	        }
	    }}},

	    {"00002357_3_X_0233_IN_D800_1044PPI_16BPC_1CH_LP07_1_615x537", {
	        {"00002357_3_X_0233_IN_D800_1044PPI_16BPC_1CH_LP07_1_615x537"
	         ".gray", 615, 537, 1044, 16, 16, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::Indanedione,
	                ProcessingMethod::Laser
	            }
	        }
	    }}},

	    {"00002357_2B_X_L02_BP_S24_1000PPI_8BPC_1CH_LP04_1_867x582", {
	        {"00002357_2B_X_L02_BP_S24_1000PPI_8BPC_1CH_LP04_1_867x582"
	         ".gray", 867, 582, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_2B_X_L02_BP_S24_1200PPI_8BPC_1CH_LP09_1_667x572", {
	        {"00002357_2B_X_L02_BP_S24_1200PPI_8BPC_1CH_LP09_1_667x572"
	         ".gray", 667, 572, 1200, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_4E_X_089_IN_D800_1112PPI_16BPC_1CH_LP09_1_551x1091", {
	        {"00002357_4E_X_089_IN_D800_1112PPI_16BPC_1CH_LP09_1_551x1091"
	         ".gray", 551, 1091, 1112, 16, 16, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::Indanedione,
	                ProcessingMethod::Laser
	            }
	        }
	    }}},

	    {"00002357_6D_X_110_WT_D800_1000PPI_8BPC_1CH_LP01_1_720x563", {
	        {"00002357_6D_X_110_WT_D800_1000PPI_8BPC_1CH_LP01_1_720x563"
	         ".gray", 720, 563, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::StickysidePowder
	            }
	        }
	    }}},

	    {"00002357_1G_L_L01_BP_S24_1000PPI_8BPC_1CH_LP02_1_770x794", {
	        {"00002357_1G_L_L01_BP_S24_1000PPI_8BPC_1CH_LP02_1_770x794"
	         ".gray", 770, 794, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_3_X_0230_IN_D800_1044PPI_16BPC_1CH_LP07_1_922x1007", {
	        {"00002357_3_X_0230_IN_D800_1044PPI_16BPC_1CH_LP07_1_922x1007"
	         ".gray", 922, 1007, 1044, 16, 16, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::Indanedione,
	                ProcessingMethod::Laser
	            }
	        }
	    }}},

	    {"00002357_1G_R_L01_BP_S24_1000PPI_8BPC_1CH_LP05_1_840x699", {
	        {"00002357_1G_R_L01_BP_S24_1000PPI_8BPC_1CH_LP05_1_840x699"
	         ".gray", 840, 699, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_1E_R_L01_BP_S24_1000PPI_8BPC_1CH_LP03_1_736x1088", {
	        {"00002357_1E_R_L01_BP_S24_1000PPI_8BPC_1CH_LP03_1_736x1088"
	         ".gray", 736, 1088, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_3_X_0230_IN_D800_1000PPI_8BPC_1CH_LP08_1_892x835", {
	        {"00002357_3_X_0230_IN_D800_1000PPI_8BPC_1CH_LP08_1_892x835"
	         ".gray", 892, 835, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::Indanedione,
	                ProcessingMethod::Laser
	            }
	        }
	    }}},

	    {"00002357_5A_X_028_IN_D800_1000PPI_8BPC_1CH_LP03_1_994x652", {
	        {"00002357_5A_X_028_IN_D800_1000PPI_8BPC_1CH_LP03_1_994x652"
	         ".gray", 994, 652, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::Indanedione,
	                ProcessingMethod::Laser
	            }
	        }
	    }}},

	    {"00002357_1D_L_L01_BP_S24_1000PPI_8BPC_1CH_LP03_1_631x920", {
	        {"00002357_1D_L_L01_BP_S24_1000PPI_8BPC_1CH_LP03_1_631x920"
	         ".gray", 631, 920, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_2B_X_L02_BP_S24_1000PPI_8BPC_1CH_LP09_1_556x477", {
	        {"00002357_2B_X_L02_BP_S24_1000PPI_8BPC_1CH_LP09_1_556x477"
	         ".gray", 556, 477, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_1D_R_L01_BP_S24_1200PPI_8BPC_1CH_LP03_1_891x1305", {
	        {"00002357_1D_R_L01_BP_S24_1200PPI_8BPC_1CH_LP03_1_891x1305"
	         ".gray", 891, 1305, 1200, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_2B_X_L02_BP_S24_1200PPI_8BPC_1CH_LP05_1_779x974", {
	        {"00002357_2B_X_L02_BP_S24_1200PPI_8BPC_1CH_LP05_1_779x974"
	         ".gray", 779, 974, 1200, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_2B_X_L02_BP_S24_1200PPI_8BPC_1CH_LP06_1_1079x839", {
	        {"00002357_2B_X_L02_BP_S24_1200PPI_8BPC_1CH_LP06_1_1079x839"
	         ".gray", 1079, 839, 1200, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_5A_X_028_IN_D800_1109PPI_16BPC_1CH_LP02_1_950x663", {
	        {"00002357_5A_X_028_IN_D800_1109PPI_16BPC_1CH_LP02_1_950x663"
	         ".gray", 950, 663, 1109, 16, 16, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::Indanedione,
	                ProcessingMethod::Laser
	            }
	        }
	    }}},

	    {"00002357_1D_L_L01_BP_S24_1000PPI_8BPC_1CH_LP05_1_713x1261", {
	        {"00002357_1D_L_L01_BP_S24_1000PPI_8BPC_1CH_LP05_1_713x1261"
	         ".gray", 713, 1261, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_6D_X_109_WT_D800_1000PPI_8BPC_1CH_LP05_1_1092x396", {
	        {"00002357_6D_X_109_WT_D800_1000PPI_8BPC_1CH_LP05_1_1092x396"
	         ".gray", 1092, 396, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::StickysidePowder
	            }
	        }
	    }}},

	    {"00002357_2B_X_L01_BP_S24_1000PPI_8BPC_1CH_LP10_1_907x974", {
	        {"00002357_2B_X_L01_BP_S24_1000PPI_8BPC_1CH_LP10_1_907x974"
	         ".gray", 907, 974, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_1G_R_L01_BP_S24_1000PPI_8BPC_1CH_LP04_1_914x813", {
	        {"00002357_1G_R_L01_BP_S24_1000PPI_8BPC_1CH_LP04_1_914x813"
	         ".gray", 914, 813, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_1E_L_L01_BP_S24_1000PPI_8BPC_1CH_LP03_1_542x642", {
	        {"00002357_1E_L_L01_BP_S24_1000PPI_8BPC_1CH_LP03_1_542x642"
	         ".gray", 542, 642, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_6D_X_109_WT_D800_1109PPI_16BPC_1CH_LP05_1_1211x439", {
	        {"00002357_6D_X_109_WT_D800_1109PPI_16BPC_1CH_LP05_1_1211x439"
	         ".gray", 1211, 439, 1109, 16, 16, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::StickysidePowder
	            }
	        }
	    }}},

	    {"00002357_1H_L_L01_BP_S24_1200PPI_8BPC_1CH_LP15_1_673x839", {
	        {"00002357_1H_L_L01_BP_S24_1200PPI_8BPC_1CH_LP15_1_673x839"
	         ".gray", 673, 839, 1200, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_1H_R_L01_BP_S24_1200PPI_8BPC_1CH_LP15_1_812x1047", {
	        {"00002357_1H_R_L01_BP_S24_1200PPI_8BPC_1CH_LP15_1_812x1047"
	         ".gray", 812, 1047, 1200, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_3_X_0233_IN_D800_1000PPI_8BPC_1CH_LP07_1_589x514", {
	        {"00002357_3_X_0233_IN_D800_1000PPI_8BPC_1CH_LP07_1_589x514"
	         ".gray", 589, 514, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::Indanedione,
	                ProcessingMethod::Laser
	            }
	        }
	    }}},

	    {"00002357_5A_X_027_IN_D800_1109PPI_16BPC_1CH_LP02_1_914x832", {
	        {"00002357_5A_X_027_IN_D800_1109PPI_16BPC_1CH_LP02_1_914x832"
	         ".gray", 914, 832, 1109, 16, 16, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::Indanedione,
	                ProcessingMethod::Laser
	            }
	        }
	    }}},

	    {"00002357_6D_X_110_WT_D800_1000PPI_8BPC_1CH_LP08_1_389x344", {
	        {"00002357_6D_X_110_WT_D800_1000PPI_8BPC_1CH_LP08_1_389x344"
	         ".gray", 389, 344, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::StickysidePowder
	            }
	        }
	    }}},

	    {"00002357_1G_L_L01_BP_S24_1200PPI_8BPC_1CH_LP02_1_924x953", {
	        {"00002357_1G_L_L01_BP_S24_1200PPI_8BPC_1CH_LP02_1_924x953"
	         ".gray", 924, 953, 1200, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_5A_X_028_IN_D800_1000PPI_8BPC_1CH_LP02_1_857x598", {
	        {"00002357_5A_X_028_IN_D800_1000PPI_8BPC_1CH_LP02_1_857x598"
	         ".gray", 857, 598, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::Indanedione,
	                ProcessingMethod::Laser
	            }
	        }
	    }}},

	    {"00002357_1H_L_L01_BP_S24_1200PPI_8BPC_1CH_LP04_1_557x729", {
	        {"00002357_1H_L_L01_BP_S24_1200PPI_8BPC_1CH_LP04_1_557x729"
	         ".gray", 557, 729, 1200, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_5A_X_028_IN_D800_1109PPI_16BPC_1CH_LP01_1_1006x791", {
	        {"00002357_5A_X_028_IN_D800_1109PPI_16BPC_1CH_LP01_1_1006x791"
	         ".gray", 1006, 791, 1109, 16, 16, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::Indanedione,
	                ProcessingMethod::Laser
	            }
	        }
	    }}},

	    {"00002357_5A_X_028_IN_D800_1109PPI_16BPC_1CH_LP05_1_807x760", {
	        {"00002357_5A_X_028_IN_D800_1109PPI_16BPC_1CH_LP05_1_807x760"
	         ".gray", 807, 760, 1109, 16, 16, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::Indanedione,
	                ProcessingMethod::Laser
	            }
	        }
	    }}},

	    {"00002357_1E_R_L01_BP_S24_1200PPI_8BPC_1CH_LP03_1_883x1306", {
	        {"00002357_1E_R_L01_BP_S24_1200PPI_8BPC_1CH_LP03_1_883x1306"
	         ".gray", 883, 1306, 1200, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_6A_X_210_BT_D800_1430PPI_16BPC_1CH_LP01_1_579x839", {
	        {"00002357_6A_X_210_BT_D800_1430PPI_16BPC_1CH_LP01_1_579x839"
	         ".gray", 579, 839, 1430, 16, 16, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::StickysidePowder
	            }
	        }
	    }}},

	    {"00002357_4E_X_089_IN_D800_1000PPI_8BPC_1CH_LP09_1_496x981", {
	        {"00002357_4E_X_089_IN_D800_1000PPI_8BPC_1CH_LP09_1_496x981"
	         ".gray", 496, 981, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::Indanedione,
	                ProcessingMethod::Laser
	            }
	        }
	    }}},

	    {"00002357_3_X_0239_IN_D800_1044PPI_16BPC_1CH_LP16_1_827x1024", {
	        {"00002357_3_X_0239_IN_D800_1044PPI_16BPC_1CH_LP16_1_827x1024"
	         ".gray", 827, 1024, 1044, 16, 16, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::Indanedione,
	                ProcessingMethod::Laser
	            }
	        }
	    }}},

	    {"00002357_2B_X_L02_BP_S24_1200PPI_8BPC_1CH_LP04_1_1041x699", {
	        {"00002357_2B_X_L02_BP_S24_1200PPI_8BPC_1CH_LP04_1_1041x699"
	         ".gray", 1041, 699, 1200, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_3_X_0239_IN_D800_1000PPI_8BPC_1CH_LP16_1_792x981", {
	        {"00002357_3_X_0239_IN_D800_1000PPI_8BPC_1CH_LP16_1_792x981"
	         ".gray", 792, 981, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::Indanedione,
	                ProcessingMethod::Laser
	            }
	        }
	    }}},

	    {"00002357_1E_L_L01_BP_S24_1200PPI_8BPC_1CH_LP03_1_650x770", {
	        {"00002357_1E_L_L01_BP_S24_1200PPI_8BPC_1CH_LP03_1_650x770"
	         ".gray", 650, 770, 1200, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentLift,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::BlackPowder
	            }
	        }
	    }}},

	    {"00002357_5A_X_028_IN_D800_1000PPI_8BPC_1CH_LP05_1_728x685", {
	        {"00002357_5A_X_028_IN_D800_1000PPI_8BPC_1CH_LP05_1_728x685"
	         ".gray", 728, 685, 1000, 8, 8, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::Indanedione,
	                ProcessingMethod::Laser
	            }
	        }
	    }}},

	    {"00002357_3_X_0230_IN_D800_1044PPI_16BPC_1CH_LP02_1_406x671", {
	        {"00002357_3_X_0230_IN_D800_1044PPI_16BPC_1CH_LP02_1_406x671"
	         ".gray", 406, 671, 1044, 16, 16, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::Indanedione,
	                ProcessingMethod::Laser
	            }
	        }
	    }}},

	    {"00002357_3_X_0230_IN_D800_1044PPI_16BPC_1CH_LP08_1_931x872", {
	        {"00002357_3_X_0230_IN_D800_1044PPI_16BPC_1CH_LP08_1_931x872"
	         ".gray", 931, 872, 1044, 16, 16, EFS{0, Impression::Latent,
	            FrictionRidgeCaptureTechnology::LatentImpression,
	            FrictionRidgeGeneralizedPosition::UnknownFinger, {},
	            std::vector<ProcessingMethod>{
	                ProcessingMethod::Indanedione,
	                ProcessingMethod::Laser
	            }
	        }
	    }}}
	};


	/** Reference images to be made into templates. */
	const std::vector<ImageSet> References {
	    {"00002644", {
	        {"00002644_V_500_roll_01_800x750.gray", 800, 750, 500,
	            8, 8, EFS{0, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002644_V_500_roll_06_800x750.gray", 800, 750, 500,
	            8, 8, EFS{1, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002644_V_500_roll_07_800x750.gray", 800, 750, 500,
	            8, 8, EFS{2, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002644_V_500_roll_09_800x750.gray", 800, 750, 500,
	            8, 8, EFS{3, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002644_V_500_roll_08_800x750.gray", 800, 750, 500,
	            8, 8, EFS{4, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002644_V_500_roll_10_800x750.gray", 800, 750, 500,
	            8, 8, EFS{5, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002644_V_500_roll_02_800x750.gray", 800, 750, 500,
	            8, 8, EFS{6, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002644_V_500_roll_05_800x750.gray", 800, 750, 500,
	            8, 8, EFS{7, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002644_V_500_roll_04_800x750.gray", 800, 750, 500,
	            8, 8, EFS{8, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002644_V_500_roll_03_800x750.gray", 800, 750, 500,
	            8, 8, EFS{9, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002325", {
	        {"00002325_R_500_slap_01_378x539.gray", 378, 539, 500,
	            8, 8, EFS{0, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002325_R_500_slap_10_256x451.gray", 256, 451, 500,
	            8, 8, EFS{1, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002325_R_500_slap_09_286x427.gray", 286, 427, 500,
	            8, 8, EFS{2, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002325_R_500_slap_08_296x458.gray", 296, 458, 500,
	            8, 8, EFS{3, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002325_R_500_slap_05_256x422.gray", 256, 422, 500,
	            8, 8, EFS{4, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002325_R_500_slap_03_307x500.gray", 307, 500, 500,
	            8, 8, EFS{5, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002325_R_500_slap_06_356x566.gray", 356, 566, 500,
	            8, 8, EFS{6, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002325_R_500_slap_02_281x507.gray", 281, 507, 500,
	            8, 8, EFS{7, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002325_R_500_slap_04_274x464.gray", 274, 464, 500,
	            8, 8, EFS{8, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002325_R_500_slap_07_281x476.gray", 281, 476, 500,
	            8, 8, EFS{9, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002449", {
	        {"00002449_A_500_roll_01_512x512.gray", 512, 512, 500,
	            8, 8, EFS{0, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002449_A_500_roll_06_512x512.gray", 512, 512, 500,
	            8, 8, EFS{1, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002449_A_500_roll_07_512x512.gray", 512, 512, 500,
	            8, 8, EFS{2, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002449_A_500_roll_09_512x512.gray", 512, 512, 500,
	            8, 8, EFS{3, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002449_A_500_roll_08_512x512.gray", 512, 512, 500,
	            8, 8, EFS{4, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002449_A_500_roll_10_512x512.gray", 512, 512, 500,
	            8, 8, EFS{5, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002449_A_500_roll_02_512x512.gray", 512, 512, 500,
	            8, 8, EFS{6, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002449_A_500_roll_05_512x512.gray", 512, 512, 500,
	            8, 8, EFS{7, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002449_A_500_roll_04_512x512.gray", 512, 512, 500,
	            8, 8, EFS{8, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002449_A_500_roll_03_512x512.gray", 512, 512, 500,
	            8, 8, EFS{9, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002606", {
	        {"00002606_U_1000_roll_02_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{0, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002606_U_1000_roll_10_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{1, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002606_U_1000_roll_05_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{2, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002606_U_1000_roll_04_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{3, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002606_U_1000_roll_03_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{4, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002606_U_1000_roll_09_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{5, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002606_U_1000_roll_01_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{6, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002606_U_1000_roll_06_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{7, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002606_U_1000_roll_07_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{8, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002606_U_1000_roll_08_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{9, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002327", {
	        {"00002327_R_500_slap_10_256x432.gray", 256, 432, 500,
	            8, 8, EFS{0, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002327_R_500_slap_06_318x561.gray", 318, 561, 500,
	            8, 8, EFS{1, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002327_R_500_slap_09_267x498.gray", 267, 498, 500,
	            8, 8, EFS{2, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002327_R_500_slap_02_269x490.gray", 269, 490, 500,
	            8, 8, EFS{3, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002327_R_500_slap_04_265x516.gray", 265, 516, 500,
	            8, 8, EFS{4, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002327_R_500_slap_05_256x438.gray", 256, 438, 500,
	            8, 8, EFS{5, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002327_R_500_slap_08_271x522.gray", 271, 522, 500,
	            8, 8, EFS{6, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002327_R_500_slap_07_301x478.gray", 301, 478, 500,
	            8, 8, EFS{7, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002327_R_500_slap_01_360x598.gray", 360, 598, 500,
	            8, 8, EFS{8, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002327_R_500_slap_03_263x493.gray", 263, 493, 500,
	            8, 8, EFS{9, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002634", {
	        {"00002634_V_500_roll_08_800x750.gray", 800, 750, 500,
	            8, 8, EFS{0, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002634_V_500_roll_09_800x750.gray", 800, 750, 500,
	            8, 8, EFS{1, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002634_V_500_roll_04_800x750.gray", 800, 750, 500,
	            8, 8, EFS{2, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002634_V_500_roll_03_800x750.gray", 800, 750, 500,
	            8, 8, EFS{3, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002634_V_500_roll_10_800x750.gray", 800, 750, 500,
	            8, 8, EFS{4, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002634_V_500_roll_02_800x750.gray", 800, 750, 500,
	            8, 8, EFS{5, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002634_V_500_roll_05_800x750.gray", 800, 750, 500,
	            8, 8, EFS{6, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002634_V_500_roll_07_800x750.gray", 800, 750, 500,
	            8, 8, EFS{7, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002634_V_500_roll_01_800x750.gray", 800, 750, 500,
	            8, 8, EFS{8, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002634_V_500_roll_06_800x750.gray", 800, 750, 500,
	            8, 8, EFS{9, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002334", {
	        {"00002334_R_500_slap_02_285x422.gray", 285, 422, 500,
	            8, 8, EFS{0, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002334_R_500_slap_09_256x400.gray", 256, 400, 500,
	            8, 8, EFS{1, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002334_R_500_slap_04_256x420.gray", 256, 420, 500,
	            8, 8, EFS{2, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002334_R_500_slap_08_258x412.gray", 258, 412, 500,
	            8, 8, EFS{3, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002334_R_500_slap_06_350x532.gray", 350, 532, 500,
	            8, 8, EFS{4, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002334_R_500_slap_05_256x317.gray", 256, 317, 500,
	            8, 8, EFS{5, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002334_R_500_slap_01_353x503.gray", 353, 503, 500,
	            8, 8, EFS{6, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002334_R_500_slap_07_266x412.gray", 266, 412, 500,
	            8, 8, EFS{7, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002334_R_500_slap_10_256x350.gray", 256, 350, 500,
	            8, 8, EFS{8, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002334_R_500_slap_03_278x435.gray", 278, 435, 500,
	            8, 8, EFS{9, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002447", {
	        {"00002447_A_500_roll_05_512x512.gray", 512, 512, 500,
	            8, 8, EFS{0, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002447_A_500_roll_02_512x512.gray", 512, 512, 500,
	            8, 8, EFS{1, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002447_A_500_roll_10_512x512.gray", 512, 512, 500,
	            8, 8, EFS{2, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002447_A_500_roll_03_512x512.gray", 512, 512, 500,
	            8, 8, EFS{3, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002447_A_500_roll_04_512x512.gray", 512, 512, 500,
	            8, 8, EFS{4, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002447_A_500_roll_09_512x512.gray", 512, 512, 500,
	            8, 8, EFS{5, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002447_A_500_roll_08_512x512.gray", 512, 512, 500,
	            8, 8, EFS{6, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002447_A_500_roll_06_512x512.gray", 512, 512, 500,
	            8, 8, EFS{7, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002447_A_500_roll_01_512x512.gray", 512, 512, 500,
	            8, 8, EFS{8, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002447_A_500_roll_07_512x512.gray", 512, 512, 500,
	            8, 8, EFS{9, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002646", {
	        {"00002646_V_500_roll_02_800x750.gray", 800, 750, 500,
	            8, 8, EFS{0, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002646_V_500_roll_05_800x750.gray", 800, 750, 500,
	            8, 8, EFS{1, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002646_V_500_roll_10_800x750.gray", 800, 750, 500,
	            8, 8, EFS{2, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002646_V_500_roll_04_800x750.gray", 800, 750, 500,
	            8, 8, EFS{3, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002646_V_500_roll_03_800x750.gray", 800, 750, 500,
	            8, 8, EFS{4, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002646_V_500_roll_09_800x750.gray", 800, 750, 500,
	            8, 8, EFS{5, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002646_V_500_roll_08_800x750.gray", 800, 750, 500,
	            8, 8, EFS{6, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002646_V_500_roll_01_800x750.gray", 800, 750, 500,
	            8, 8, EFS{7, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002646_V_500_roll_06_800x750.gray", 800, 750, 500,
	            8, 8, EFS{8, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002646_V_500_roll_07_800x750.gray", 800, 750, 500,
	            8, 8, EFS{9, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002650", {
	        {"00002650_V_500_roll_10_800x750.gray", 800, 750, 500,
	            8, 8, EFS{0, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002650_V_500_roll_02_800x750.gray", 800, 750, 500,
	            8, 8, EFS{1, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002650_V_500_roll_05_800x750.gray", 800, 750, 500,
	            8, 8, EFS{2, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002650_V_500_roll_04_800x750.gray", 800, 750, 500,
	            8, 8, EFS{3, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002650_V_500_roll_03_800x750.gray", 800, 750, 500,
	            8, 8, EFS{4, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002650_V_500_roll_09_800x750.gray", 800, 750, 500,
	            8, 8, EFS{5, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002650_V_500_roll_08_800x750.gray", 800, 750, 500,
	            8, 8, EFS{6, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002650_V_500_roll_01_800x750.gray", 800, 750, 500,
	            8, 8, EFS{7, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002650_V_500_roll_06_800x750.gray", 800, 750, 500,
	            8, 8, EFS{8, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002650_V_500_roll_07_800x750.gray", 800, 750, 500,
	            8, 8, EFS{9, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002616", {
	        {"00002616_U_1000_roll_01_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{0, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002616_U_1000_roll_09_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{1, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002616_U_1000_roll_06_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{2, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002616_U_1000_roll_07_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{3, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002616_U_1000_roll_08_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{4, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002616_U_1000_roll_02_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{5, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002616_U_1000_roll_10_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{6, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002616_U_1000_roll_05_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{7, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002616_U_1000_roll_04_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{8, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002616_U_1000_roll_03_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{9, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002319", {
	        {"00002319_R_500_slap_01_354x503.gray", 354, 503, 500,
	            8, 8, EFS{0, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002319_R_500_slap_04_256x424.gray", 256, 424, 500,
	            8, 8, EFS{1, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002319_R_500_slap_10_256x424.gray", 256, 424, 500,
	            8, 8, EFS{2, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002319_R_500_slap_05_256x422.gray", 256, 422, 500,
	            8, 8, EFS{3, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002319_R_500_slap_02_256x394.gray", 256, 394, 500,
	            8, 8, EFS{4, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002319_R_500_slap_03_256x420.gray", 256, 420, 500,
	            8, 8, EFS{5, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002319_R_500_slap_08_280x440.gray", 280, 440, 500,
	            8, 8, EFS{6, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002319_R_500_slap_07_268x433.gray", 268, 433, 500,
	            8, 8, EFS{7, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002319_R_500_slap_09_290x456.gray", 290, 456, 500,
	            8, 8, EFS{8, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002319_R_500_slap_06_298x532.gray", 298, 532, 500,
	            8, 8, EFS{9, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002624", {
	        {"00002624_U_1000_roll_04_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{0, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002624_U_1000_roll_03_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{1, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002624_U_1000_roll_02_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{2, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002624_U_1000_roll_05_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{3, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002624_U_1000_roll_10_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{4, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002624_U_1000_roll_07_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{5, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002624_U_1000_roll_08_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{6, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002624_U_1000_roll_01_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{7, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002624_U_1000_roll_09_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{8, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002624_U_1000_roll_06_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{9, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002328", {
	        {"00002328_R_500_slap_10_256x421.gray", 256, 421, 500,
	            8, 8, EFS{0, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002328_R_500_slap_03_256x461.gray", 256, 461, 500,
	            8, 8, EFS{1, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002328_R_500_slap_05_256x379.gray", 256, 379, 500,
	            8, 8, EFS{2, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002328_R_500_slap_09_256x396.gray", 256, 396, 500,
	            8, 8, EFS{3, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002328_R_500_slap_02_256x386.gray", 256, 386, 500,
	            8, 8, EFS{4, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002328_R_500_slap_04_256x424.gray", 256, 424, 500,
	            8, 8, EFS{5, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002328_R_500_slap_06_307x485.gray", 307, 485, 500,
	            8, 8, EFS{6, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002328_R_500_slap_07_256x355.gray", 256, 355, 500,
	            8, 8, EFS{7, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002328_R_500_slap_08_256x367.gray", 256, 367, 500,
	            8, 8, EFS{8, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002328_R_500_slap_01_317x495.gray", 317, 495, 500,
	            8, 8, EFS{9, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002320", {
	        {"00002320_R_500_slap_05_256x433.gray", 256, 433, 500,
	            8, 8, EFS{0, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002320_R_500_slap_08_262x458.gray", 262, 458, 500,
	            8, 8, EFS{1, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002320_R_500_slap_01_333x492.gray", 333, 492, 500,
	            8, 8, EFS{2, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002320_R_500_slap_09_256x431.gray", 256, 431, 500,
	            8, 8, EFS{3, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002320_R_500_slap_10_256x460.gray", 256, 460, 500,
	            8, 8, EFS{4, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002320_R_500_slap_03_260x490.gray", 260, 490, 500,
	            8, 8, EFS{5, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002320_R_500_slap_06_350x532.gray", 350, 532, 500,
	            8, 8, EFS{6, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002320_R_500_slap_02_259x425.gray", 259, 425, 500,
	            8, 8, EFS{7, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002320_R_500_slap_04_256x466.gray", 256, 466, 500,
	            8, 8, EFS{8, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002320_R_500_slap_07_256x433.gray", 256, 433, 500,
	            8, 8, EFS{9, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002357", {
	        {"00002357_V_1000_roll_07_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{0, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_R_500_slap_13_2496x2560.gray", 2496, 2560, 500,
	            8, 8, EFS{1, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightFour,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_R_500_slap_09_293x399.gray", 293, 399, 500,
	            8, 8, EFS{2, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_U_500_roll_01_800x750.gray", 800, 750, 500,
	            8, 8, EFS{3, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_V_1000_roll_08_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{4, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_U_500_roll_06_800x750.gray", 800, 750, 500,
	            8, 8, EFS{5, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_R_1000_slap_01_762x1016.gray", 762, 1016, 1000,
	            8, 8, EFS{6, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_A_500_roll_06_512x512.gray", 512, 512, 500,
	            8, 8, EFS{7, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_A_500_roll_01_512x512.gray", 512, 512, 500,
	            8, 8, EFS{8, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_R_500_slap_14_2496x2560.gray", 2496, 2560, 500,
	            8, 8, EFS{9, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftFour,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_V_1000_roll_01_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{10, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_R_500_slap_15_2496x2560.gray", 2496, 2560, 500,
	            8, 8, EFS{11, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightAndLeftThumbs,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_R_1000_slap_05_512x675.gray", 512, 675, 1000,
	            8, 8, EFS{12, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_V_1000_roll_09_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{13, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_A_500_roll_07_512x512.gray", 512, 512, 500,
	            8, 8, EFS{14, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_V_1000_roll_06_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{15, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_U_500_roll_07_800x750.gray", 800, 750, 500,
	            8, 8, EFS{16, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_R_500_slap_05_256x338.gray", 256, 338, 500,
	            8, 8, EFS{17, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_V_1000_roll_04_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{18, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_R_1000_slap_07_559x766.gray", 559, 766, 1000,
	            8, 8, EFS{19, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_R_1000_slap_09_587x798.gray", 587, 798, 1000,
	            8, 8, EFS{20, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_V_1000_roll_03_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{21, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_R_500_slap_07_280x383.gray", 280, 383, 500,
	            8, 8, EFS{22, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_R_1000_slap_06_841x1012.gray", 841, 1012, 1000,
	            8, 8, EFS{23, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_V_1000_roll_02_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{24, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_V_1000_roll_05_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{25, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_V_1000_roll_10_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{26, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_A_500_roll_09_512x512.gray", 512, 512, 500,
	            8, 8, EFS{27, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_U_500_roll_09_800x750.gray", 800, 750, 500,
	            8, 8, EFS{28, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_R_1000_slap_08_559x808.gray", 559, 808, 1000,
	            8, 8, EFS{29, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_R_500_slap_08_274x403.gray", 274, 403, 500,
	            8, 8, EFS{30, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_R_500_slap_04_274x413.gray", 274, 413, 500,
	            8, 8, EFS{31, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_R_1000_slap_10_512x742.gray", 512, 742, 1000,
	            8, 8, EFS{32, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_U_500_roll_08_800x750.gray", 800, 750, 500,
	            8, 8, EFS{33, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_R_1000_slap_03_539x818.gray", 539, 818, 1000,
	            8, 8, EFS{34, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_R_500_slap_03_268x409.gray", 268, 409, 500,
	            8, 8, EFS{35, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_R_1000_slap_02_555x782.gray", 555, 782, 1000,
	            8, 8, EFS{36, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_A_500_roll_08_512x512.gray", 512, 512, 500,
	            8, 8, EFS{37, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_R_1000_slap_04_548x825.gray", 548, 825, 1000,
	            8, 8, EFS{38, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_R_500_slap_10_256x371.gray", 256, 371, 500,
	            8, 8, EFS{39, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_R_500_slap_02_278x389.gray", 278, 389, 500,
	            8, 8, EFS{40, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_R_500_slap_06_409x506.gray", 409, 506, 500,
	            8, 8, EFS{41, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_U_500_roll_10_800x750.gray", 800, 750, 500,
	            8, 8, EFS{42, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_A_500_roll_05_512x512.gray", 512, 512, 500,
	            8, 8, EFS{43, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_A_500_roll_02_512x512.gray", 512, 512, 500,
	            8, 8, EFS{44, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_U_500_roll_02_800x750.gray", 800, 750, 500,
	            8, 8, EFS{45, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_U_500_roll_05_800x750.gray", 800, 750, 500,
	            8, 8, EFS{46, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_A_500_roll_10_512x512.gray", 512, 512, 500,
	            8, 8, EFS{47, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_R_500_slap_01_379x507.gray", 379, 507, 500,
	            8, 8, EFS{48, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_U_500_roll_04_800x750.gray", 800, 750, 500,
	            8, 8, EFS{49, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_U_500_roll_03_800x750.gray", 800, 750, 500,
	            8, 8, EFS{50, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_A_500_roll_03_512x512.gray", 512, 512, 500,
	            8, 8, EFS{51, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002357_A_500_roll_04_512x512.gray", 512, 512, 500,
	            8, 8, EFS{52, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002610", {
	        {"00002610_U_1000_roll_03_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{0, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002610_U_1000_roll_04_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{1, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002610_U_1000_roll_10_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{2, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002610_U_1000_roll_05_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{3, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002610_U_1000_roll_02_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{4, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002610_U_1000_roll_08_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{5, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002610_U_1000_roll_07_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{6, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002610_U_1000_roll_06_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{7, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002610_U_1000_roll_09_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{8, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002610_U_1000_roll_01_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{9, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002611", {
	        {"00002611_U_1000_roll_07_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{0, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002611_U_1000_roll_08_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{1, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002611_U_1000_roll_01_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{2, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002611_U_1000_roll_09_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{3, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002611_U_1000_roll_06_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{4, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002611_U_1000_roll_04_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{5, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002611_U_1000_roll_03_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{6, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002611_U_1000_roll_02_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{7, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002611_U_1000_roll_05_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{8, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002611_U_1000_roll_10_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{9, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002625", {
	        {"00002625_U_1000_roll_08_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{0, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002625_U_1000_roll_07_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{1, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002625_U_1000_roll_06_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{2, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002625_U_1000_roll_09_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{3, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002625_U_1000_roll_01_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{4, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002625_U_1000_roll_03_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{5, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002625_U_1000_roll_04_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{6, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002625_U_1000_roll_10_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{7, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002625_U_1000_roll_05_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{8, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002625_U_1000_roll_02_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{9, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002329", {
	        {"00002329_R_500_slap_05_274x489.gray", 274, 489, 500,
	            8, 8, EFS{0, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002329_R_500_slap_10_317x406.gray", 317, 406, 500,
	            8, 8, EFS{1, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002329_R_500_slap_08_301x485.gray", 301, 485, 500,
	            8, 8, EFS{2, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002329_R_500_slap_09_339x510.gray", 339, 510, 500,
	            8, 8, EFS{3, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002329_R_500_slap_02_264x444.gray", 264, 444, 500,
	            8, 8, EFS{4, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002329_R_500_slap_06_412x609.gray", 412, 609, 500,
	            8, 8, EFS{5, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002329_R_500_slap_07_290x476.gray", 290, 476, 500,
	            8, 8, EFS{6, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002329_R_500_slap_03_266x488.gray", 266, 488, 500,
	            8, 8, EFS{7, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002329_R_500_slap_01_368x551.gray", 368, 551, 500,
	            8, 8, EFS{8, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002329_R_500_slap_04_316x490.gray", 316, 490, 500,
	            8, 8, EFS{9, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002317", {
	        {"00002317_R_500_slap_09_270x394.gray", 270, 394, 500,
	            8, 8, EFS{0, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002317_R_500_slap_07_275x449.gray", 275, 449, 500,
	            8, 8, EFS{1, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002317_R_500_slap_10_257x437.gray", 257, 437, 500,
	            8, 8, EFS{2, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002317_R_500_slap_01_371x604.gray", 371, 604, 500,
	            8, 8, EFS{3, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002317_R_500_slap_06_366x473.gray", 366, 473, 500,
	            8, 8, EFS{4, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002317_R_500_slap_04_279x431.gray", 279, 431, 500,
	            8, 8, EFS{5, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002317_R_500_slap_08_265x416.gray", 265, 416, 500,
	            8, 8, EFS{6, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002317_R_500_slap_02_256x370.gray", 256, 370, 500,
	            8, 8, EFS{7, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002317_R_500_slap_05_256x404.gray", 256, 404, 500,
	            8, 8, EFS{8, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002317_R_500_slap_03_256x413.gray", 256, 413, 500,
	            8, 8, EFS{9, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002640", {
	        {"00002640_V_500_roll_09_800x750.gray", 800, 750, 500,
	            8, 8, EFS{0, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002640_V_500_roll_08_800x750.gray", 800, 750, 500,
	            8, 8, EFS{1, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002640_V_500_roll_10_800x750.gray", 800, 750, 500,
	            8, 8, EFS{2, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002640_V_500_roll_02_800x750.gray", 800, 750, 500,
	            8, 8, EFS{3, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002640_V_500_roll_05_800x750.gray", 800, 750, 500,
	            8, 8, EFS{4, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002640_V_500_roll_04_800x750.gray", 800, 750, 500,
	            8, 8, EFS{5, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002640_V_500_roll_03_800x750.gray", 800, 750, 500,
	            8, 8, EFS{6, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002640_V_500_roll_01_800x750.gray", 800, 750, 500,
	            8, 8, EFS{7, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002640_V_500_roll_06_800x750.gray", 800, 750, 500,
	            8, 8, EFS{8, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002640_V_500_roll_07_800x750.gray", 800, 750, 500,
	            8, 8, EFS{9, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002313", {
	        {"00002313_R_1000_slap_15_4992x5120.gray", 4992, 5120, 1000,
	            8, 8, EFS{0, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightAndLeftThumbs,
	            {}, {}, ValueAssessment::Value}},
	        {"00002313_R_1000_slap_13_4992x5120.gray", 4992, 5120, 1000,
	            8, 8, EFS{1, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightFour,
	            {}, {}, ValueAssessment::Value}},
	        {"00002313_R_1000_slap_14_4992x5120.gray", 4992, 5120, 1000,
	            8, 8, EFS{2, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftFour,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002315", {
	        {"00002315_R_500_slap_10_256x409.gray", 256, 409, 500,
	            8, 8, EFS{0, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002315_R_500_slap_09_262x429.gray", 262, 429, 500,
	            8, 8, EFS{1, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002315_R_500_slap_04_256x435.gray", 256, 435, 500,
	            8, 8, EFS{2, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002315_R_500_slap_08_277x459.gray", 277, 459, 500,
	            8, 8, EFS{3, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002315_R_500_slap_03_288x458.gray", 288, 458, 500,
	            8, 8, EFS{4, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002315_R_500_slap_06_341x575.gray", 341, 575, 500,
	            8, 8, EFS{5, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002315_R_500_slap_02_283x443.gray", 283, 443, 500,
	            8, 8, EFS{6, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002315_R_500_slap_01_310x588.gray", 310, 588, 500,
	            8, 8, EFS{7, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002315_R_500_slap_05_256x411.gray", 256, 411, 500,
	            8, 8, EFS{8, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002315_R_500_slap_07_319x485.gray", 319, 485, 500,
	            8, 8, EFS{9, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002641", {
	        {"00002641_V_500_roll_04_800x750.gray", 800, 750, 500,
	            8, 8, EFS{0, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002641_V_500_roll_03_800x750.gray", 800, 750, 500,
	            8, 8, EFS{1, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002641_V_500_roll_10_800x750.gray", 800, 750, 500,
	            8, 8, EFS{2, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002641_V_500_roll_02_800x750.gray", 800, 750, 500,
	            8, 8, EFS{3, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002641_V_500_roll_05_800x750.gray", 800, 750, 500,
	            8, 8, EFS{4, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002641_V_500_roll_08_800x750.gray", 800, 750, 500,
	            8, 8, EFS{5, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002641_V_500_roll_09_800x750.gray", 800, 750, 500,
	            8, 8, EFS{6, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002641_V_500_roll_07_800x750.gray", 800, 750, 500,
	            8, 8, EFS{7, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002641_V_500_roll_01_800x750.gray", 800, 750, 500,
	            8, 8, EFS{8, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002641_V_500_roll_06_800x750.gray", 800, 750, 500,
	            8, 8, EFS{9, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002332", {
	        {"00002332_R_500_slap_05_256x381.gray", 256, 381, 500,
	            8, 8, EFS{0, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002332_R_500_slap_08_284x422.gray", 284, 422, 500,
	            8, 8, EFS{1, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002332_R_500_slap_01_320x562.gray", 320, 562, 500,
	            8, 8, EFS{2, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002332_R_500_slap_02_256x411.gray", 256, 411, 500,
	            8, 8, EFS{3, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002332_R_500_slap_04_256x390.gray", 256, 390, 500,
	            8, 8, EFS{4, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002332_R_500_slap_06_315x512.gray", 315, 512, 500,
	            8, 8, EFS{5, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002332_R_500_slap_07_256x428.gray", 256, 428, 500,
	            8, 8, EFS{6, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002332_R_500_slap_10_256x366.gray", 256, 366, 500,
	            8, 8, EFS{7, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002332_R_500_slap_03_256x382.gray", 256, 382, 500,
	            8, 8, EFS{8, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002332_R_500_slap_09_256x429.gray", 256, 429, 500,
	            8, 8, EFS{9, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002651", {
	        {"00002651_V_500_roll_08_800x750.gray", 800, 750, 500,
	            8, 8, EFS{0, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002651_V_500_roll_09_800x750.gray", 800, 750, 500,
	            8, 8, EFS{1, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002651_V_500_roll_04_800x750.gray", 800, 750, 500,
	            8, 8, EFS{2, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002651_V_500_roll_03_800x750.gray", 800, 750, 500,
	            8, 8, EFS{3, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002651_V_500_roll_10_800x750.gray", 800, 750, 500,
	            8, 8, EFS{4, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002651_V_500_roll_02_800x750.gray", 800, 750, 500,
	            8, 8, EFS{5, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002651_V_500_roll_05_800x750.gray", 800, 750, 500,
	            8, 8, EFS{6, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002651_V_500_roll_07_800x750.gray", 800, 750, 500,
	            8, 8, EFS{7, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002651_V_500_roll_01_800x750.gray", 800, 750, 500,
	            8, 8, EFS{8, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002651_V_500_roll_06_800x750.gray", 800, 750, 500,
	            8, 8, EFS{9, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002633", {
	        {"00002633_V_500_roll_09_800x750.gray", 800, 750, 500,
	            8, 8, EFS{0, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002633_V_500_roll_08_800x750.gray", 800, 750, 500,
	            8, 8, EFS{1, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002633_V_500_roll_02_800x750.gray", 800, 750, 500,
	            8, 8, EFS{2, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002633_V_500_roll_05_800x750.gray", 800, 750, 500,
	            8, 8, EFS{3, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002633_V_500_roll_10_800x750.gray", 800, 750, 500,
	            8, 8, EFS{4, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002633_V_500_roll_04_800x750.gray", 800, 750, 500,
	            8, 8, EFS{5, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002633_V_500_roll_03_800x750.gray", 800, 750, 500,
	            8, 8, EFS{6, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002633_V_500_roll_01_800x750.gray", 800, 750, 500,
	            8, 8, EFS{7, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002633_V_500_roll_06_800x750.gray", 800, 750, 500,
	            8, 8, EFS{8, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002633_V_500_roll_07_800x750.gray", 800, 750, 500,
	            8, 8, EFS{9, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002302", {
	        {"00002302_R_1000_slap_15_4992x5120.gray", 4992, 5120, 1000,
	            8, 8, EFS{0, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightAndLeftThumbs,
	            {}, {}, ValueAssessment::Value}},
	        {"00002302_R_1000_slap_14_4992x5120.gray", 4992, 5120, 1000,
	            8, 8, EFS{1, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftFour,
	            {}, {}, ValueAssessment::Value}},
	        {"00002302_R_1000_slap_13_4992x5120.gray", 4992, 5120, 1000,
	            8, 8, EFS{2, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightFour,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002337", {
	        {"00002337_R_500_slap_05_256x438.gray", 256, 438, 500,
	            8, 8, EFS{0, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002337_R_500_slap_09_256x487.gray", 256, 487, 500,
	            8, 8, EFS{1, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002337_R_500_slap_03_298x471.gray", 298, 471, 500,
	            8, 8, EFS{2, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002337_R_500_slap_08_280x486.gray", 280, 486, 500,
	            8, 8, EFS{3, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002337_R_500_slap_06_385x607.gray", 385, 607, 500,
	            8, 8, EFS{4, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002337_R_500_slap_04_276x464.gray", 276, 464, 500,
	            8, 8, EFS{5, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002337_R_500_slap_01_386x581.gray", 386, 581, 500,
	            8, 8, EFS{6, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002337_R_500_slap_10_256x441.gray", 256, 441, 500,
	            8, 8, EFS{7, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002337_R_500_slap_07_258x476.gray", 258, 476, 500,
	            8, 8, EFS{8, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002337_R_500_slap_02_285x469.gray", 285, 469, 500,
	            8, 8, EFS{9, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002454", {
	        {"00002454_A_500_roll_07_512x512.gray", 512, 512, 500,
	            8, 8, EFS{0, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002454_A_500_roll_06_512x512.gray", 512, 512, 500,
	            8, 8, EFS{1, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002454_A_500_roll_01_512x512.gray", 512, 512, 500,
	            8, 8, EFS{2, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002454_A_500_roll_08_512x512.gray", 512, 512, 500,
	            8, 8, EFS{3, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002454_A_500_roll_09_512x512.gray", 512, 512, 500,
	            8, 8, EFS{4, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002454_A_500_roll_03_512x512.gray", 512, 512, 500,
	            8, 8, EFS{5, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002454_A_500_roll_04_512x512.gray", 512, 512, 500,
	            8, 8, EFS{6, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002454_A_500_roll_10_512x512.gray", 512, 512, 500,
	            8, 8, EFS{7, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002454_A_500_roll_05_512x512.gray", 512, 512, 500,
	            8, 8, EFS{8, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002454_A_500_roll_02_512x512.gray", 512, 512, 500,
	            8, 8, EFS{9, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002321", {
	        {"00002321_R_500_slap_04_273x424.gray", 273, 424, 500,
	            8, 8, EFS{0, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002321_R_500_slap_05_256x403.gray", 256, 403, 500,
	            8, 8, EFS{1, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002321_R_500_slap_03_298x441.gray", 298, 441, 500,
	            8, 8, EFS{2, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002321_R_500_slap_02_277x422.gray", 277, 422, 500,
	            8, 8, EFS{3, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002321_R_500_slap_06_370x551.gray", 370, 551, 500,
	            8, 8, EFS{4, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002321_R_500_slap_01_364x553.gray", 364, 553, 500,
	            8, 8, EFS{5, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002321_R_500_slap_07_256x399.gray", 256, 399, 500,
	            8, 8, EFS{6, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002321_R_500_slap_08_268x431.gray", 268, 431, 500,
	            8, 8, EFS{7, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002321_R_500_slap_09_256x406.gray", 256, 406, 500,
	            8, 8, EFS{8, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002321_R_500_slap_10_256x379.gray", 256, 379, 500,
	            8, 8, EFS{9, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002314", {
	        {"00002314_R_500_slap_08_256x445.gray", 256, 445, 500,
	            8, 8, EFS{0, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002314_R_500_slap_05_256x384.gray", 256, 384, 500,
	            8, 8, EFS{1, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002314_R_500_slap_03_256x393.gray", 256, 393, 500,
	            8, 8, EFS{2, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002314_R_500_slap_04_256x470.gray", 256, 470, 500,
	            8, 8, EFS{3, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002314_R_500_slap_02_256x373.gray", 256, 373, 500,
	            8, 8, EFS{4, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002314_R_500_slap_01_318x518.gray", 318, 518, 500,
	            8, 8, EFS{5, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002314_R_500_slap_06_297x550.gray", 297, 550, 500,
	            8, 8, EFS{6, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002314_R_500_slap_10_256x417.gray", 256, 417, 500,
	            8, 8, EFS{7, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002314_R_500_slap_07_256x459.gray", 256, 459, 500,
	            8, 8, EFS{8, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002314_R_500_slap_09_256x466.gray", 256, 466, 500,
	            8, 8, EFS{9, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002330", {
	        {"00002330_R_500_slap_08_275x500.gray", 275, 500, 500,
	            8, 8, EFS{0, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002330_R_500_slap_02_256x473.gray", 256, 473, 500,
	            8, 8, EFS{1, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002330_R_500_slap_06_356x614.gray", 356, 614, 500,
	            8, 8, EFS{2, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002330_R_500_slap_10_256x428.gray", 256, 428, 500,
	            8, 8, EFS{3, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002330_R_500_slap_07_261x494.gray", 261, 494, 500,
	            8, 8, EFS{4, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002330_R_500_slap_09_259x506.gray", 259, 506, 500,
	            8, 8, EFS{5, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002330_R_500_slap_04_256x489.gray", 256, 489, 500,
	            8, 8, EFS{6, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002330_R_500_slap_05_256x437.gray", 256, 437, 500,
	            8, 8, EFS{7, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002330_R_500_slap_03_256x457.gray", 256, 457, 500,
	            8, 8, EFS{8, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002330_R_500_slap_01_351x569.gray", 351, 569, 500,
	            8, 8, EFS{9, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002326", {
	        {"00002326_R_500_slap_09_407x480.gray", 407, 480, 500,
	            8, 8, EFS{0, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002326_R_500_slap_01_414x595.gray", 414, 595, 500,
	            8, 8, EFS{1, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002326_R_500_slap_07_336x567.gray", 336, 567, 500,
	            8, 8, EFS{2, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002326_R_500_slap_02_372x471.gray", 372, 471, 500,
	            8, 8, EFS{3, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002326_R_500_slap_08_408x457.gray", 408, 457, 500,
	            8, 8, EFS{4, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002326_R_500_slap_03_384x471.gray", 384, 471, 500,
	            8, 8, EFS{5, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002326_R_500_slap_06_412x565.gray", 412, 565, 500,
	            8, 8, EFS{6, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002326_R_500_slap_04_368x475.gray", 368, 475, 500,
	            8, 8, EFS{7, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002326_R_500_slap_05_299x384.gray", 299, 384, 500,
	            8, 8, EFS{8, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002326_R_500_slap_10_318x422.gray", 318, 422, 500,
	            8, 8, EFS{9, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002303", {
	        {"00002303_R_1000_slap_15_4992x5120.gray", 4992, 5120, 1000,
	            8, 8, EFS{0, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightAndLeftThumbs,
	            {}, {}, ValueAssessment::Value}},
	        {"00002303_R_1000_slap_13_4992x5120.gray", 4992, 5120, 1000,
	            8, 8, EFS{1, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightFour,
	            {}, {}, ValueAssessment::Value}},
	        {"00002303_R_1000_slap_14_4992x5120.gray", 4992, 5120, 1000,
	            8, 8, EFS{2, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftFour,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002304", {
	        {"00002304_R_1000_slap_13_4992x5120.gray", 4992, 5120, 1000,
	            8, 8, EFS{0, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightFour,
	            {}, {}, ValueAssessment::Value}},
	        {"00002304_R_1000_slap_14_4992x5120.gray", 4992, 5120, 1000,
	            8, 8, EFS{1, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftFour,
	            {}, {}, ValueAssessment::Value}},
	        {"00002304_R_1000_slap_15_4992x5120.gray", 4992, 5120, 1000,
	            8, 8, EFS{2, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightAndLeftThumbs,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002448", {
	        {"00002448_A_500_roll_07_512x512.gray", 512, 512, 500,
	            8, 8, EFS{0, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002448_A_500_roll_01_512x512.gray", 512, 512, 500,
	            8, 8, EFS{1, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002448_A_500_roll_06_512x512.gray", 512, 512, 500,
	            8, 8, EFS{2, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002448_A_500_roll_04_512x512.gray", 512, 512, 500,
	            8, 8, EFS{3, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002448_A_500_roll_03_512x512.gray", 512, 512, 500,
	            8, 8, EFS{4, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002448_A_500_roll_10_512x512.gray", 512, 512, 500,
	            8, 8, EFS{5, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002448_A_500_roll_02_512x512.gray", 512, 512, 500,
	            8, 8, EFS{6, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002448_A_500_roll_05_512x512.gray", 512, 512, 500,
	            8, 8, EFS{7, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002448_A_500_roll_08_512x512.gray", 512, 512, 500,
	            8, 8, EFS{8, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002448_A_500_roll_09_512x512.gray", 512, 512, 500,
	            8, 8, EFS{9, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002645", {
	        {"00002645_V_500_roll_07_800x750.gray", 800, 750, 500,
	            8, 8, EFS{0, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002645_V_500_roll_01_800x750.gray", 800, 750, 500,
	            8, 8, EFS{1, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002645_V_500_roll_06_800x750.gray", 800, 750, 500,
	            8, 8, EFS{2, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002645_V_500_roll_04_800x750.gray", 800, 750, 500,
	            8, 8, EFS{3, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002645_V_500_roll_03_800x750.gray", 800, 750, 500,
	            8, 8, EFS{4, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002645_V_500_roll_10_800x750.gray", 800, 750, 500,
	            8, 8, EFS{5, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002645_V_500_roll_02_800x750.gray", 800, 750, 500,
	            8, 8, EFS{6, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002645_V_500_roll_05_800x750.gray", 800, 750, 500,
	            8, 8, EFS{7, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002645_V_500_roll_08_800x750.gray", 800, 750, 500,
	            8, 8, EFS{8, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002645_V_500_roll_09_800x750.gray", 800, 750, 500,
	            8, 8, EFS{9, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002649", {
	        {"00002649_V_500_roll_07_800x750.gray", 800, 750, 500,
	            8, 8, EFS{0, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002649_V_500_roll_06_800x750.gray", 800, 750, 500,
	            8, 8, EFS{1, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002649_V_500_roll_01_800x750.gray", 800, 750, 500,
	            8, 8, EFS{2, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002649_V_500_roll_03_800x750.gray", 800, 750, 500,
	            8, 8, EFS{3, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002649_V_500_roll_04_800x750.gray", 800, 750, 500,
	            8, 8, EFS{4, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002649_V_500_roll_10_800x750.gray", 800, 750, 500,
	            8, 8, EFS{5, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002649_V_500_roll_05_800x750.gray", 800, 750, 500,
	            8, 8, EFS{6, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002649_V_500_roll_02_800x750.gray", 800, 750, 500,
	            8, 8, EFS{7, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002649_V_500_roll_08_800x750.gray", 800, 750, 500,
	            8, 8, EFS{8, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002649_V_500_roll_09_800x750.gray", 800, 750, 500,
	            8, 8, EFS{9, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002455", {
	        {"00002455_A_500_roll_06_512x512.gray", 512, 512, 500,
	            8, 8, EFS{0, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002455_A_500_roll_01_512x512.gray", 512, 512, 500,
	            8, 8, EFS{1, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002455_A_500_roll_07_512x512.gray", 512, 512, 500,
	            8, 8, EFS{2, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002455_A_500_roll_10_512x512.gray", 512, 512, 500,
	            8, 8, EFS{3, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002455_A_500_roll_05_512x512.gray", 512, 512, 500,
	            8, 8, EFS{4, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002455_A_500_roll_02_512x512.gray", 512, 512, 500,
	            8, 8, EFS{5, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002455_A_500_roll_03_512x512.gray", 512, 512, 500,
	            8, 8, EFS{6, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002455_A_500_roll_04_512x512.gray", 512, 512, 500,
	            8, 8, EFS{7, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002455_A_500_roll_09_512x512.gray", 512, 512, 500,
	            8, 8, EFS{8, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002455_A_500_roll_08_512x512.gray", 512, 512, 500,
	            8, 8, EFS{9, Impression::RolledContactlessMoving,
	            FrictionRidgeCaptureTechnology::OpticalDirect,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002312", {
	        {"00002312_R_1000_slap_15_4992x5120.gray", 4992, 5120, 1000,
	            8, 8, EFS{0, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightAndLeftThumbs,
	            {}, {}, ValueAssessment::Value}},
	        {"00002312_R_1000_slap_14_4992x5120.gray", 4992, 5120, 1000,
	            8, 8, EFS{1, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftFour,
	            {}, {}, ValueAssessment::Value}},
	        {"00002312_R_1000_slap_13_4992x5120.gray", 4992, 5120, 1000,
	            8, 8, EFS{2, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightFour,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002636", {
	        {"00002636_V_500_roll_07_800x750.gray", 800, 750, 500,
	            8, 8, EFS{0, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002636_V_500_roll_01_800x750.gray", 800, 750, 500,
	            8, 8, EFS{1, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002636_V_500_roll_06_800x750.gray", 800, 750, 500,
	            8, 8, EFS{2, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002636_V_500_roll_04_800x750.gray", 800, 750, 500,
	            8, 8, EFS{3, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002636_V_500_roll_03_800x750.gray", 800, 750, 500,
	            8, 8, EFS{4, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002636_V_500_roll_02_800x750.gray", 800, 750, 500,
	            8, 8, EFS{5, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002636_V_500_roll_05_800x750.gray", 800, 750, 500,
	            8, 8, EFS{6, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002636_V_500_roll_10_800x750.gray", 800, 750, 500,
	            8, 8, EFS{7, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002636_V_500_roll_08_800x750.gray", 800, 750, 500,
	            8, 8, EFS{8, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002636_V_500_roll_09_800x750.gray", 800, 750, 500,
	            8, 8, EFS{9, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002604", {
	        {"00002604_U_1000_roll_03_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{0, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002604_U_1000_roll_04_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{1, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002604_U_1000_roll_10_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{2, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002604_U_1000_roll_05_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{3, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002604_U_1000_roll_02_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{4, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002604_U_1000_roll_08_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{5, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002604_U_1000_roll_07_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{6, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002604_U_1000_roll_06_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{7, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002604_U_1000_roll_01_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{8, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002604_U_1000_roll_09_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{9, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002602", {
	        {"00002602_U_1000_roll_09_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{0, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002602_U_1000_roll_01_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{1, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002602_U_1000_roll_06_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{2, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002602_U_1000_roll_07_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{3, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002602_U_1000_roll_08_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{4, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002602_U_1000_roll_02_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{5, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002602_U_1000_roll_10_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{6, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002602_U_1000_roll_05_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{7, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002602_U_1000_roll_04_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{8, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002602_U_1000_roll_03_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{9, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002626", {
	        {"00002626_U_1000_roll_05_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{0, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002626_U_1000_roll_10_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{1, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002626_U_1000_roll_02_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{2, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002626_U_1000_roll_03_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{3, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002626_U_1000_roll_04_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{4, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002626_U_1000_roll_06_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{5, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002626_U_1000_roll_09_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{6, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002626_U_1000_roll_01_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{7, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002626_U_1000_roll_08_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{8, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002626_U_1000_roll_07_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{9, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002307", {
	        {"00002307_R_1000_slap_15_4992x5120.gray", 4992, 5120, 1000,
	            8, 8, EFS{0, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightAndLeftThumbs,
	            {}, {}, ValueAssessment::Value}},
	        {"00002307_R_1000_slap_13_4992x5120.gray", 4992, 5120, 1000,
	            8, 8, EFS{1, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightFour,
	            {}, {}, ValueAssessment::Value}},
	        {"00002307_R_1000_slap_14_4992x5120.gray", 4992, 5120, 1000,
	            8, 8, EFS{2, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftFour,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002615", {
	        {"00002615_U_1000_roll_04_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{0, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002615_U_1000_roll_03_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{1, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002615_U_1000_roll_02_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{2, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002615_U_1000_roll_05_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{3, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002615_U_1000_roll_10_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{4, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002615_U_1000_roll_07_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{5, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002615_U_1000_roll_08_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{6, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002615_U_1000_roll_01_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{7, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002615_U_1000_roll_09_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{8, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002615_U_1000_roll_06_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{9, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002621", {
	        {"00002621_U_1000_roll_03_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{0, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002621_U_1000_roll_04_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{1, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002621_U_1000_roll_10_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{2, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002621_U_1000_roll_05_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{3, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002621_U_1000_roll_02_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{4, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002621_U_1000_roll_08_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{5, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002621_U_1000_roll_07_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{6, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002621_U_1000_roll_06_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{7, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002621_U_1000_roll_09_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{8, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002621_U_1000_roll_01_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{9, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002614", {
	        {"00002614_U_1000_roll_08_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{0, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002614_U_1000_roll_07_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{1, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002614_U_1000_roll_06_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{2, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002614_U_1000_roll_09_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{3, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002614_U_1000_roll_01_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{4, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002614_U_1000_roll_03_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{5, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002614_U_1000_roll_04_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{6, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002614_U_1000_roll_10_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{7, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002614_U_1000_roll_05_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{8, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002614_U_1000_roll_02_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{9, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002612", {
	        {"00002612_U_1000_roll_02_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{0, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002612_U_1000_roll_10_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{1, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002612_U_1000_roll_05_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{2, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002612_U_1000_roll_04_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{3, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002612_U_1000_roll_03_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{4, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002612_U_1000_roll_01_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{5, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002612_U_1000_roll_09_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{6, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002612_U_1000_roll_06_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{7, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002612_U_1000_roll_07_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{8, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002612_U_1000_roll_08_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{9, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002596", {
	        {"00002596_U_1000_roll_04_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{0, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002596_U_1000_roll_03_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{1, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002596_U_1000_roll_02_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{2, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002596_U_1000_roll_10_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{3, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002596_U_1000_roll_05_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{4, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002596_U_1000_roll_07_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{5, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002596_U_1000_roll_08_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{6, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002596_U_1000_roll_09_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{7, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002596_U_1000_roll_01_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{8, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002596_U_1000_roll_06_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{9, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002630", {
	        {"00002630_U_1000_roll_04_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{0, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002630_U_1000_roll_03_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{1, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002630_U_1000_roll_02_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{2, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002630_U_1000_roll_05_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{3, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002630_U_1000_roll_10_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{4, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftLittle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002630_U_1000_roll_07_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{5, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftIndex,
	            {}, {}, ValueAssessment::Value}},
	        {"00002630_U_1000_roll_08_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{6, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftMiddle,
	            {}, {}, ValueAssessment::Value}},
	        {"00002630_U_1000_roll_09_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{7, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftRing,
	            {}, {}, ValueAssessment::Value}},
	        {"00002630_U_1000_roll_01_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{8, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightThumb,
	            {}, {}, ValueAssessment::Value}},
	        {"00002630_U_1000_roll_06_1600x1500.gray", 1600, 1500, 1000,
	            8, 8, EFS{9, Impression::RolledContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftThumb,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002310", {
	        {"00002310_R_1000_slap_13_4992x5120.gray", 4992, 5120, 1000,
	            8, 8, EFS{0, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightFour,
	            {}, {}, ValueAssessment::Value}},
	        {"00002310_R_1000_slap_14_4992x5120.gray", 4992, 5120, 1000,
	            8, 8, EFS{1, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftFour,
	            {}, {}, ValueAssessment::Value}},
	        {"00002310_R_1000_slap_15_4992x5120.gray", 4992, 5120, 1000,
	            8, 8, EFS{2, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightAndLeftThumbs,
	            {}, {}, ValueAssessment::Value}}}
	    },

	    {"00002306", {
	        {"00002306_R_1000_slap_15_4992x5120.gray", 4992, 5120, 1000,
	            8, 8, EFS{0, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightAndLeftThumbs,
	            {}, {}, ValueAssessment::Value}},
	        {"00002306_R_1000_slap_14_4992x5120.gray", 4992, 5120, 1000,
	            8, 8, EFS{1, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::LeftFour,
	            {}, {}, ValueAssessment::Value}},
	        {"00002306_R_1000_slap_13_4992x5120.gray", 4992, 5120, 1000,
	            8, 8, EFS{2, Impression::PlainContact,
	            FrictionRidgeCaptureTechnology::OpticalTIRBright,
	            FrictionRidgeGeneralizedPosition::RightFour,
	            {}, {}, ValueAssessment::Value}}}
	    }
	};
}

#endif /* ELFT_VALIDATION_DATA_H_ */
