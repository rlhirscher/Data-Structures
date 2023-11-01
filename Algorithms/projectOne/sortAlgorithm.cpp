/*
   Ryan Hirscher, Michael, and William
   csc2710
   10/8/2021
   /home/students/rhirscher/csc2710/programs/projectOne

   This program demonstrates several sorting algorithms with different datasets including: random, almost sorted, reverse sorted, and with many duplicates. The sorting algorithms include: selection sort, exchange sort, bubble sort, insertion sort, merge sort, quicksort, and heapsort. The program takes a command line option where you may specify if you want to print the datasets unsorted instead of the default option which is to print the sorted datasets of each algorithm. The program is made up of a group of 3 people: Ryan, Michael, and William.

   Compile: g++ sortAlgorithm.cpp -o testProg
   Execution 1: ./testProg
   Execution 2: ./testProg -d
*/ 

#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>
#include <chrono> 
void selectionSort(int x[], int n, int &count, double &time);
void exchangeSort(int myArray[], int arraySize, int &count, double &time);
void bubbleSort(int x[], int n, int &count, double &time);
void insertionSort(int arr[], int n, int &count, double &time);
void mergeSort(int array[], int const begin, int const end, int &count, double &time);
void merge(int array[], int const left, int const mid, int const right, int &count);
void quickSort(int arr[], int low, int high, int &count, double &time);
int partition (int arr[], int low, int high, int &count);
void heapSort(int arr[], int n, int &count, double &time);
void heapify(int arr[], int n, int i, int &count);
//void fillArray(int myArray[], int arraySize);
//void fillAlmost(int myArray[], int arraySize);
//void fillDup(int myArray[], int arraySize);
//void fillRev(int myArray[], int arraySize);
void printArray(int myArray[], int arraySize);
void swap(int &x, int &y);
using namespace std;
int main(int argc, char *argv[])
{
////////////////////////////////////// DATASET ARRAYS ///////////////////////////

   int randomArray[1000] = {320, 886, 92, 993, 445, 976, 429, 87, 165, 705, 598, 643, 6, 833, 911, 223, 647, 103, 544, 871, 496, 845, 838, 12, 446, 810, 644, 626, 764, 975, 892, 763, 668, 733, 561, 679, 106, 718, 881, 384, 461, 715, 448, 981, 162, 404, 7, 94, 310, 752, 732, 99, 181, 428, 597, 27, 464, 636, 684, 355, 560, 425, 375, 788, 252, 344, 215, 254, 189, 328, 682, 290, 781, 789, 813, 198, 207, 146, 790, 392, 258, 600, 547, 942, 516, 367, 491, 225, 579, 860, 926, 804, 282, 139, 922, 296, 793, 904, 624, 77, 455, 596, 823, 971, 977, 839, 859, 157, 637, 120, 321, 199, 699, 648, 564, 843, 453, 379, 465, 466, 505, 185, 535, 498, 351, 243, 71, 869, 753, 854, 33, 119, 531, 893, 741, 26, 510, 950, 812, 332, 484, 179, 237, 339, 798, 620, 154, 1000, 366, 147, 31, 17, 228, 330, 878, 378, 301, 548, 707, 877, 450, 541, 177, 386, 18, 744, 40, 232, 914, 292, 858, 916, 432, 299, 619, 640, 395, 986, 249, 760, 302, 645, 14, 941, 616, 210, 725, 173, 246, 304, 805, 818, 408, 728, 795, 100, 222, 834, 394, 946, 503, 857, 743, 32, 691, 476, 317, 711, 472, 3, 997, 137, 35, 563, 418, 49, 836, 360, 661, 778, 78, 81, 689, 963, 359, 370, 842, 108, 424, 925, 528, 454, 167, 599, 902, 338, 55, 540, 792, 8, 217, 652, 397, 41, 722, 325, 422, 241, 126, 573, 480, 349, 208, 358, 888, 796, 861, 196, 312, 870, 151, 153, 551, 513, 697, 635, 523, 915, 962, 42, 342, 952, 884, 749, 903, 724, 514, 820, 305, 152, 614, 539, 24, 784, 628, 47, 966, 615, 550, 401, 124, 811, 826, 621, 856, 336, 201, 387, 500, 474, 487, 730, 853, 416, 409, 102, 307, 758, 709, 489, 212, 116, 313, 284, 221, 747, 66, 775, 693, 69, 101, 759, 678, 768, 369, 269, 944, 729, 493, 664, 672, 537, 646, 37, 172, 587, 415, 899, 825, 291, 607, 114, 638, 86, 654, 726, 821, 586, 495, 141, 757, 895, 374, 710, 405, 190, 901, 714, 924, 274, 365, 511, 434, 440, 281, 527, 417, 674, 534, 382, 159, 255, 592, 2, 303, 133, 608, 954, 912, 935, 898, 786, 809, 270, 140, 266, 671, 75, 512, 549, 93, 110, 936, 68, 554, 931, 765, 80, 998, 874, 309, 611, 482, 97, 293, 244, 402, 323, 419, 107, 273, 276, 361, 56, 663, 184, 657, 272, 98, 420, 327, 82, 211, 203, 882, 675, 987, 138, 406, 456, 939, 734, 940, 745, 245, 239, 814, 72, 770, 623, 411, 937, 125, 216, 508, 470, 634, 802, 343, 205, 806, 777, 30, 435, 322, 388, 988, 381, 700, 145, 934, 224, 883, 891, 552, 403, 128, 447, 873, 951, 521, 350, 568, 257, 25, 90, 822, 585, 999, 306, 932, 622, 63, 584, 832, 504, 36, 978, 132, 45, 1, 533, 542, 135, 287, 740, 979, 412, 353, 59, 52, 696, 676, 991, 955, 149, 572, 785, 161, 28, 961, 475, 315, 819, 46, 717, 160, 737, 308, 569, 144, 756, 111, 701, 352, 617, 688, 220, 267, 192, 380, 444, 426, 969, 148, 967, 463, 601, 150, 721, 289, 766, 719, 5, 260, 867, 526, 326, 499, 20, 319, 670, 451, 865, 485, 960, 662, 437, 73, 187, 945, 669, 984, 529, 681, 713, 329, 783, 115, 459, 174, 39, 261, 594, 171, 575, 831, 692, 863, 195, 54, 927, 848, 277, 889, 591, 197, 155, 48, 143, 930, 655, 990, 441, 816, 773, 318, 21, 268, 690, 771, 347, 852, 314, 423, 348, 602, 735, 827, 565, 750, 685, 194, 683, 89, 16, 438, 85, 357, 800, 815, 188, 694, 285, 218, 191, 335, 164, 964, 134, 761, 769, 76, 929, 264, 994, 364, 507, 840, 543, 829, 589, 570, 202, 452, 996, 762, 943, 427, 182, 74, 88, 658, 462, 603, 706, 799, 649, 193, 439, 974, 501, 656, 471, 906, 803, 324, 577, 844, 371, 9, 230, 398, 502, 4, 43, 253, 479, 478, 410, 885, 311, 250, 995, 665, 413, 686, 19, 233, 736, 123, 553, 175, 918, 767, 209, 879, 755, 38, 251, 896, 96, 695, 469, 407, 680, 131, 235, 604, 558, 742, 231, 168, 633, 113, 875, 286, 333, 522, 949, 95, 980, 837, 612, 373, 631, 650, 70, 855, 846, 206, 368, 557, 851, 830, 213, 136, 880, 751, 473, 163, 142, 659, 262, 653, 538, 546, 519, 390, 118, 53, 376, 968, 776, 708, 121, 497, 431, 772, 156, 396, 117, 920, 84, 651, 595, 247, 278, 112, 566, 234, 817, 923, 79, 530, 436, 265, 774, 300, 559, 468, 787, 295, 567, 748, 331, 130, 876, 229, 849, 953, 956, 582, 400, 562, 62, 158, 259, 905, 109, 629, 746, 973, 393, 850, 864, 104, 723, 226, 283, 477, 11, 702, 590, 739, 556, 263, 275, 824, 630, 334, 22, 983, 83, 385, 868, 992, 57, 345, 894, 340, 716, 667, 443, 828, 67, 492, 297, 238, 703, 506, 256, 467, 15, 481, 60, 890, 791, 29, 399, 58, 509, 170, 341, 938, 958, 279, 176, 129, 605, 337, 532, 921, 957, 571, 660, 200, 363, 515, 346, 588, 712, 494, 808, 627, 51, 520, 985, 91, 807, 780, 947, 928, 65, 389, 242, 965, 910, 887, 574, 545, 44, 524, 356, 61, 430, 536, 779, 580, 458, 593, 835, 948, 214, 900, 64, 618, 186, 391, 609, 271, 578, 227, 959, 909, 576, 460, 433, 727, 517, 298, 913, 632, 34, 613, 933, 248, 383, 639, 377, 797, 754, 166, 280, 105, 698, 178, 704, 866, 731, 183, 583, 801, 518, 204, 897, 50, 907, 919, 982, 240, 989, 488, 219, 169, 555, 970, 13, 862, 581, 362, 642, 917, 294, 354, 316, 421, 236, 414, 677, 666, 525, 908, 180, 288, 372, 457, 10, 442, 490, 841, 782, 122, 483, 44};
   //fillArray(randomArray, 1000);

   int almostArray[1000] = {320, 886, 92, 993, 445, 976, 429, 87, 165, 705, 598, 643, 6, 833, 911, 223, 647, 103, 544, 871, 496, 845, 838, 12, 446, 810, 644, 626, 764, 975, 892, 763, 668, 733, 561, 679, 106, 718, 881, 384, 461, 715, 448, 981, 162, 404, 7, 94, 310, 752, 732, 99, 181, 428, 597, 27, 464, 636, 684, 355, 560, 425, 375, 788, 252, 344, 215, 254, 189, 328, 682, 290, 781, 789, 813, 198, 207, 146, 790, 392, 258, 600, 547, 942, 516, 367, 491, 225, 579, 860, 926, 804, 282, 139, 922, 296, 793, 904, 624, 77, 455, 596, 823, 971, 977, 839, 859, 157, 637, 120, 321, 199, 699, 648, 564, 843, 453, 379, 465, 466, 505, 185, 535, 498, 351, 243, 71, 869, 753, 854, 33, 119, 531, 893, 741, 26, 510, 950, 812, 332, 484, 179, 237, 339, 798, 620, 154, 1000, 366, 147, 31, 17, 228, 330, 878, 378, 301, 548, 707, 877, 450, 541, 177, 386, 18, 744, 40, 232, 914, 292, 858, 916, 432, 299, 619, 640, 395, 986, 249, 760, 302, 645, 14, 941, 616, 210, 725, 173, 246, 304, 805, 818, 408, 728, 795, 100, 222, 834, 394, 946, 503, 857, 743, 32, 691, 476, 317, 711, 472, 3, 997, 137, 35, 563, 418, 49, 836, 360, 661, 778, 78, 81, 689, 963, 359, 370, 842, 108, 424, 925, 528, 454, 167, 599, 902, 338, 55, 540, 792, 8, 217, 652, 397, 41, 722, 325, 422, 241, 126, 573, 480, 349, 208, 358, 888, 796, 861, 196, 312, 870, 151, 153, 551, 513, 697, 635, 523, 915, 962, 42, 342, 952, 884, 749, 903, 724, 514, 820, 305, 152, 614, 539, 24, 784, 628, 47, 966, 615, 550, 401, 124, 811, 826, 621, 856, 336, 201, 387, 500, 474, 487, 730, 853, 416, 409, 102, 307, 758, 709, 489, 212, 116, 313, 284, 221, 747, 66, 775, 693, 69, 101, 759, 678, 768, 369, 269, 944, 729, 493, 664, 672, 537, 646, 37, 172, 587, 415, 899, 825, 291, 607, 114, 638, 86, 654, 726, 821, 586, 495, 141, 757, 895, 374, 710, 405, 190, 901, 714, 924, 274, 365, 511, 434, 440, 281, 527, 417, 674, 534, 382, 159, 255, 592, 2, 303, 133, 608, 954, 912, 935, 898, 786, 809, 270, 140, 266, 671, 75, 512, 549, 93, 110, 936, 68, 554, 931, 765, 80, 998, 874, 309, 611, 482, 97, 293, 244, 402, 323, 419, 107, 273, 276, 361, 56, 663, 184, 657, 272, 98, 420, 327, 82, 211, 203, 882, 675, 987, 138, 406, 456, 939, 734, 940, 745, 245, 239, 814, 72, 770, 623, 411, 937, 125, 216, 508, 470, 634, 802, 343, 205, 806, 777, 30, 435, 322, 388, 988, 381, 700, 145, 934, 224, 883, 891, 552, 403, 128, 447, 873, 951, 521, 350, 568, 257, 25, 90, 822, 585, 999, 306, 932, 622, 63, 584, 832, 504, 36, 978, 132, 45, 1, 533, 542, 135, 287, 740, 979, 412, 353, 59, 52, 696, 676, 991, 955, 149, 572, 785, 161, 28, 961, 475, 315, 819, 46, 717, 160, 737, 308, 569, 144, 756, 111, 701, 352, 617, 688, 220, 267, 192, 380, 444, 426, 969, 148, 967, 463, 601, 150, 721, 289, 766, 719, 5, 260, 867, 526, 326, 499, 20, 319, 670, 451, 865, 485, 960, 662, 437, 73, 187, 945, 669, 984, 529, 681, 713, 329, 783, 115, 459, 174, 39, 261, 594, 171, 575, 831, 692, 863, 195, 54, 927, 848, 277, 889, 591, 197, 155, 48, 143, 930, 655, 990, 441, 816, 773, 318, 21, 268, 690, 771, 347, 852, 314, 423, 348, 602, 735, 827, 565, 750, 685, 194, 683, 89, 16, 438, 85, 357, 800, 815, 188, 694, 285, 218, 191, 335, 164, 964, 134, 761, 769, 76, 929, 264, 994, 364, 507, 840, 543, 829, 589, 570, 202, 452, 996, 762, 943, 427, 182, 74, 88, 658, 462, 603, 706, 799, 649, 193, 439, 974, 501, 656, 471, 906, 803, 324, 577, 844, 371, 9, 230, 398, 502, 4, 43, 253, 479, 478, 410, 885, 311, 250, 995, 665, 413, 686, 19, 233, 736, 123, 553, 175, 918, 767, 209, 879, 755, 38, 251, 896, 96, 695, 469, 407, 680, 131, 235, 604, 558, 742, 231, 168, 633, 113, 875, 286, 333, 522, 949, 95, 980, 837, 612, 373, 631, 650, 70, 855, 846, 206, 368, 557, 851, 830, 213, 136, 880, 751, 473, 163, 142, 659, 262, 653, 538, 546, 519, 390, 118, 53, 376, 968, 776, 708, 121, 497, 431, 772, 156, 396, 117, 920, 84, 651, 595, 247, 278, 112, 566, 234, 817, 923, 79, 530, 436, 265, 774, 300, 559, 468, 787, 295, 567, 748, 331, 130, 876, 229, 849, 953, 956, 582, 400, 562, 62, 158, 259, 905, 109, 629, 746, 973, 393, 850, 864, 104, 723, 226, 283, 477, 11, 702, 590, 739, 556, 263, 275, 824, 630, 334, 22, 983, 83, 385, 868, 992, 57, 345, 894, 340, 716, 667, 443, 828, 67, 492, 297, 238, 703, 506, 256, 467, 15, 481, 60, 890, 791, 29, 399, 58, 509, 170, 341, 938, 958, 279, 176, 129, 605, 337, 532, 921, 957, 571, 660, 200, 363, 515, 346, 588, 712, 494, 808, 627, 51, 520, 985, 91, 807, 780, 947, 928, 65, 389, 242, 965, 910, 887, 574, 545, 44, 524, 356, 61, 430, 536, 779, 580, 458, 593, 835, 948, 214, 900, 64, 618, 186, 391, 609, 271, 578, 227, 959, 909, 576, 460, 433, 727, 517, 298, 913, 632, 34, 613, 933, 248, 383, 639, 377, 797, 754, 166, 280, 105, 698, 178, 704, 866, 731, 183, 583, 801, 518, 204, 897, 50, 907, 919, 982, 240, 989, 488, 219, 169, 555, 970, 13, 862, 581, 362, 642, 917, 294, 354, 316, 421, 236, 414, 677, 666, 525, 908, 180, 288, 372, 457, 10, 442, 490, 841, 782, 122, 483, 44};
   //fillAlmost(almostArray, 1000);
   //fillDup(dupArray, 1000);
   int dupArray[1000] = {320, 886, 92, 993, 445, 976, 429, 87, 165, 705, 598, 643, 6, 833, 911, 223, 647, 103, 544, 871, 496, 845, 838, 12, 446, 810, 644, 626, 764, 975, 892, 763, 668, 733, 561, 679, 106, 718, 881, 384, 461, 715, 448, 981, 162, 404, 7, 94, 310, 752, 732, 99, 181, 428, 597, 27, 464, 636, 684, 355, 560, 425, 375, 788, 252, 344, 215, 254, 189, 328, 682, 290, 781, 789, 813, 198, 207, 146, 790, 392, 258, 600, 547, 942, 516, 367, 491, 225, 579, 860, 926, 804, 282, 139, 922, 296, 793, 904, 624, 77, 455, 596, 823, 971, 977, 839, 859, 157, 637, 120, 321, 199, 699, 648, 564, 843, 453, 379, 465, 466, 505, 185, 535, 498, 351, 243, 71, 869, 753, 854, 33, 119, 531, 893, 741, 26, 510, 950, 812, 332, 484, 179, 237, 339, 798, 620, 154, 1000, 366, 147, 31, 17, 228, 330, 878, 378, 301, 548, 707, 877, 450, 541, 177, 386, 18, 744, 40, 232, 914, 292, 858, 916, 432, 299, 619, 640, 395, 986, 249, 760, 302, 645, 14, 941, 616, 210, 725, 173, 246, 304, 805, 818, 408, 728, 795, 100, 222, 834, 394, 946, 503, 857, 743, 32, 691, 476, 317, 711, 472, 3, 997, 137, 35, 563, 418, 49, 836, 360, 661, 778, 78, 81, 689, 963, 359, 370, 842, 108, 424, 925, 528, 454, 167, 599, 902, 338, 55, 540, 792, 8, 217, 652, 397, 41, 722, 325, 422, 241, 126, 573, 480, 349, 208, 358, 888, 796, 861, 196, 312, 870, 151, 153, 551, 513, 697, 635, 523, 915, 962, 42, 342, 952, 884, 749, 903, 724, 514, 820, 305, 152, 614, 539, 24, 784, 628, 47, 966, 615, 550, 401, 124, 811, 826, 621, 856, 336, 201, 387, 500, 474, 487, 730, 853, 416, 409, 102, 307, 758, 709, 489, 212, 116, 313, 284, 221, 747, 66, 775, 693, 69, 101, 759, 678, 768, 369, 269, 944, 729, 493, 664, 672, 537, 646, 37, 172, 587, 415, 899, 825, 291, 607, 114, 638, 86, 654, 726, 821, 586, 495, 141, 757, 895, 374, 710, 405, 190, 901, 714, 924, 274, 365, 511, 434, 440, 281, 527, 417, 674, 534, 382, 159, 255, 592, 2, 303, 133, 608, 954, 912, 935, 898, 786, 809, 270, 140, 266, 671, 75, 512, 549, 93, 110, 936, 68, 554, 931, 765, 80, 998, 874, 309, 611, 482, 97, 293, 244, 402, 323, 419, 107, 273, 276, 361, 56, 663, 184, 657, 272, 98, 420, 327, 82, 211, 203, 882, 675, 987, 138, 406, 456, 939, 734, 940, 745, 245, 239, 814, 72, 770, 623, 411, 937, 125, 216, 508, 470, 634, 802, 343, 205, 806, 777, 30, 435, 322, 388, 988, 381, 700, 145, 934, 224, 883, 891, 552, 403, 128, 447, 873, 951, 521, 350, 568, 257, 25, 90, 822, 585, 999, 306, 932, 622, 63, 584, 832, 504, 36, 978, 132, 45, 1, 533, 542, 135, 287, 740, 979, 412, 353, 59, 52, 696, 676, 991, 955, 149, 572, 785, 161, 28, 961, 475, 315, 819, 46, 717, 160, 737, 308, 569, 144, 756, 111, 701, 352, 617, 688, 220, 267, 192, 380, 444, 426, 969, 148, 967, 463, 601, 150, 721, 289, 766, 719, 5, 260, 867, 526, 326, 499, 20, 319, 670, 451, 865, 485, 960, 662, 437, 73, 187, 945, 669, 984, 529, 681, 713, 329, 783, 115, 459, 174, 39, 261, 594, 171, 575, 831, 692, 863, 195, 54, 927, 848, 277, 889, 591, 197, 155, 48, 143, 930, 655, 990, 441, 816, 773, 318, 21, 268, 690, 771, 347, 852, 314, 423, 348, 602, 735, 827, 565, 750, 685, 194, 683, 89, 16, 438, 85, 357, 800, 815, 188, 694, 285, 218, 191, 335, 164, 964, 134, 761, 769, 76, 929, 264, 994, 364, 507, 840, 543, 829, 589, 570, 202, 452, 996, 762, 943, 427, 182, 74, 88, 658, 462, 603, 706, 799, 649, 193, 439, 974, 501, 656, 471, 906, 803, 324, 577, 844, 371, 9, 230, 398, 502, 4, 43, 253, 479, 478, 410, 885, 311, 250, 995, 665, 413, 686, 19, 233, 736, 123, 553, 175, 918, 767, 209, 879, 755, 38, 251, 896, 96, 695, 469, 407, 680, 131, 235, 604, 558, 742, 231, 168, 633, 113, 875, 286, 333, 522, 949, 95, 980, 837, 612, 373, 631, 650, 70, 855, 846, 206, 368, 557, 851, 830, 213, 136, 880, 751, 473, 163, 142, 659, 262, 653, 538, 546, 519, 390, 118, 53, 376, 968, 776, 708, 121, 497, 431, 772, 156, 396, 117, 920, 84, 651, 595, 247, 278, 112, 566, 234, 817, 923, 79, 530, 436, 265, 774, 300, 559, 468, 787, 295, 567, 748, 331, 130, 876, 229, 849, 953, 956, 582, 400, 562, 62, 158, 259, 905, 109, 629, 746, 973, 393, 850, 864, 104, 723, 226, 283, 477, 11, 702, 590, 739, 556, 263, 275, 824, 630, 334, 22, 983, 83, 385, 868, 992, 57, 345, 894, 340, 716, 667, 443, 828, 67, 492, 297, 238, 703, 506, 256, 467, 15, 481, 60, 890, 791, 29, 399, 58, 509, 170, 341, 938, 958, 279, 176, 129, 605, 337, 532, 921, 957, 571, 660, 200, 363, 515, 346, 588, 712, 494, 808, 627, 51, 520, 985, 91, 807, 780, 947, 928, 65, 389, 242, 965, 910, 887, 574, 545, 44, 524, 356, 61, 430, 536, 779, 580, 458, 593, 835, 948, 214, 900, 64, 618, 186, 391, 609, 271, 578, 227, 959, 909, 576, 460, 433, 727, 517, 298, 913, 632, 34, 613, 933, 248, 383, 639, 377, 797, 754, 166, 280, 105, 698, 178, 704, 866, 731, 183, 583, 801, 518, 204, 897, 50, 907, 919, 982, 240, 989, 488, 219, 169, 555, 970, 13, 862, 581, 362, 642, 917, 294, 354, 316, 421, 236, 414, 677, 666, 525, 908, 180, 288, 372, 457, 10, 442, 490, 841, 782, 122, 483, 44};
   //fillRev(revArray, 1000);
   int revArray[1000] = {320, 886, 92, 993, 445, 976, 429, 87, 165, 705, 598, 643, 6, 833, 911, 223, 647, 103, 544, 871, 496, 845, 838, 12, 446, 810, 644, 626, 764, 975, 892, 763, 668, 733, 561, 679, 106, 718, 881, 384, 461, 715, 448, 981, 162, 404, 7, 94, 310, 752, 732, 99, 181, 428, 597, 27, 464, 636, 684, 355, 560, 425, 375, 788, 252, 344, 215, 254, 189, 328, 682, 290, 781, 789, 813, 198, 207, 146, 790, 392, 258, 600, 547, 942, 516, 367, 491, 225, 579, 860, 926, 804, 282, 139, 922, 296, 793, 904, 624, 77, 455, 596, 823, 971, 977, 839, 859, 157, 637, 120, 321, 199, 699, 648, 564, 843, 453, 379, 465, 466, 505, 185, 535, 498, 351, 243, 71, 869, 753, 854, 33, 119, 531, 893, 741, 26, 510, 950, 812, 332, 484, 179, 237, 339, 798, 620, 154, 1000, 366, 147, 31, 17, 228, 330, 878, 378, 301, 548, 707, 877, 450, 541, 177, 386, 18, 744, 40, 232, 914, 292, 858, 916, 432, 299, 619, 640, 395, 986, 249, 760, 302, 645, 14, 941, 616, 210, 725, 173, 246, 304, 805, 818, 408, 728, 795, 100, 222, 834, 394, 946, 503, 857, 743, 32, 691, 476, 317, 711, 472, 3, 997, 137, 35, 563, 418, 49, 836, 360, 661, 778, 78, 81, 689, 963, 359, 370, 842, 108, 424, 925, 528, 454, 167, 599, 902, 338, 55, 540, 792, 8, 217, 652, 397, 41, 722, 325, 422, 241, 126, 573, 480, 349, 208, 358, 888, 796, 861, 196, 312, 870, 151, 153, 551, 513, 697, 635, 523, 915, 962, 42, 342, 952, 884, 749, 903, 724, 514, 820, 305, 152, 614, 539, 24, 784, 628, 47, 966, 615, 550, 401, 124, 811, 826, 621, 856, 336, 201, 387, 500, 474, 487, 730, 853, 416, 409, 102, 307, 758, 709, 489, 212, 116, 313, 284, 221, 747, 66, 775, 693, 69, 101, 759, 678, 768, 369, 269, 944, 729, 493, 664, 672, 537, 646, 37, 172, 587, 415, 899, 825, 291, 607, 114, 638, 86, 654, 726, 821, 586, 495, 141, 757, 895, 374, 710, 405, 190, 901, 714, 924, 274, 365, 511, 434, 440, 281, 527, 417, 674, 534, 382, 159, 255, 592, 2, 303, 133, 608, 954, 912, 935, 898, 786, 809, 270, 140, 266, 671, 75, 512, 549, 93, 110, 936, 68, 554, 931, 765, 80, 998, 874, 309, 611, 482, 97, 293, 244, 402, 323, 419, 107, 273, 276, 361, 56, 663, 184, 657, 272, 98, 420, 327, 82, 211, 203, 882, 675, 987, 138, 406, 456, 939, 734, 940, 745, 245, 239, 814, 72, 770, 623, 411, 937, 125, 216, 508, 470, 634, 802, 343, 205, 806, 777, 30, 435, 322, 388, 988, 381, 700, 145, 934, 224, 883, 891, 552, 403, 128, 447, 873, 951, 521, 350, 568, 257, 25, 90, 822, 585, 999, 306, 932, 622, 63, 584, 832, 504, 36, 978, 132, 45, 1, 533, 542, 135, 287, 740, 979, 412, 353, 59, 52, 696, 676, 991, 955, 149, 572, 785, 161, 28, 961, 475, 315, 819, 46, 717, 160, 737, 308, 569, 144, 756, 111, 701, 352, 617, 688, 220, 267, 192, 380, 444, 426, 969, 148, 967, 463, 601, 150, 721, 289, 766, 719, 5, 260, 867, 526, 326, 499, 20, 319, 670, 451, 865, 485, 960, 662, 437, 73, 187, 945, 669, 984, 529, 681, 713, 329, 783, 115, 459, 174, 39, 261, 594, 171, 575, 831, 692, 863, 195, 54, 927, 848, 277, 889, 591, 197, 155, 48, 143, 930, 655, 990, 441, 816, 773, 318, 21, 268, 690, 771, 347, 852, 314, 423, 348, 602, 735, 827, 565, 750, 685, 194, 683, 89, 16, 438, 85, 357, 800, 815, 188, 694, 285, 218, 191, 335, 164, 964, 134, 761, 769, 76, 929, 264, 994, 364, 507, 840, 543, 829, 589, 570, 202, 452, 996, 762, 943, 427, 182, 74, 88, 658, 462, 603, 706, 799, 649, 193, 439, 974, 501, 656, 471, 906, 803, 324, 577, 844, 371, 9, 230, 398, 502, 4, 43, 253, 479, 478, 410, 885, 311, 250, 995, 665, 413, 686, 19, 233, 736, 123, 553, 175, 918, 767, 209, 879, 755, 38, 251, 896, 96, 695, 469, 407, 680, 131, 235, 604, 558, 742, 231, 168, 633, 113, 875, 286, 333, 522, 949, 95, 980, 837, 612, 373, 631, 650, 70, 855, 846, 206, 368, 557, 851, 830, 213, 136, 880, 751, 473, 163, 142, 659, 262, 653, 538, 546, 519, 390, 118, 53, 376, 968, 776, 708, 121, 497, 431, 772, 156, 396, 117, 920, 84, 651, 595, 247, 278, 112, 566, 234, 817, 923, 79, 530, 436, 265, 774, 300, 559, 468, 787, 295, 567, 748, 331, 130, 876, 229, 849, 953, 956, 582, 400, 562, 62, 158, 259, 905, 109, 629, 746, 973, 393, 850, 864, 104, 723, 226, 283, 477, 11, 702, 590, 739, 556, 263, 275, 824, 630, 334, 22, 983, 83, 385, 868, 992, 57, 345, 894, 340, 716, 667, 443, 828, 67, 492, 297, 238, 703, 506, 256, 467, 15, 481, 60, 890, 791, 29, 399, 58, 509, 170, 341, 938, 958, 279, 176, 129, 605, 337, 532, 921, 957, 571, 660, 200, 363, 515, 346, 588, 712, 494, 808, 627, 51, 520, 985, 91, 807, 780, 947, 928, 65, 389, 242, 965, 910, 887, 574, 545, 44, 524, 356, 61, 430, 536, 779, 580, 458, 593, 835, 948, 214, 900, 64, 618, 186, 391, 609, 271, 578, 227, 959, 909, 576, 460, 433, 727, 517, 298, 913, 632, 34, 613, 933, 248, 383, 639, 377, 797, 754, 166, 280, 105, 698, 178, 704, 866, 731, 183, 583, 801, 518, 204, 897, 50, 907, 919, 982, 240, 989, 488, 219, 169, 555, 970, 13, 862, 581, 362, 642, 917, 294, 354, 316, 421, 236, 414, 677, 666, 525, 908, 180, 288, 372, 457, 10, 442, 490, 841, 782, 122, 483, 44};
   string check;
   if (argc == 2)
   {
      check = argv[1]; //Take argument sub 1 and store into a string to compare
      if (check == "-d")
      {
         cout << "---------START DATASETS---------" << endl;
         cout << "[Random array with potential duplicates] - unsorted" << endl;
         //printArray(randomArray, 1000);
         cout << endl << "[Almost sorted array with no duplicates] - unsorted" << endl;
         //printArray(almostArray, 1000);
         cout << endl << "[Random array with many duplicates] - unsorted" << endl;
         //printArray(dupArray, 1000);
         cout << endl << "[Reversely sorted array with no duplicates] - unsorted" << endl;
         //printArray(revArray, 1000);
         cout << endl;
         cout << "---------END DATASETS---------" << endl;
         exit(1);
      }
      else
      {
         cout << "Invalid option. Exit." << endl;
         exit(1);
      }
   }
   else if (argc > 2)
   {
      cout << "Invalid option. Exit." << endl;
      exit(1);
   }
   int count = 0;
   double time = 0;
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// SORTING ALGORITHMS //////////////////////////
/////////Selection Sort

   cout << "---------START SELECTION SORT---------" << endl;
   selectionSort(randomArray, 1000, count, time);
   cout << "[Random array with potential duplicates] - swaps: " << count << endl << "Time: " << time << " nanoseconds" << endl;
   /*printArray(randomArray, 1000);
   selectionSort(almostArray, 1000, count, time);
   cout << endl << "[Almost sorted array with no duplicates] - swaps: " << count << endl << "Time: " << time << " nanoseconds" << endl;
   printArray(almostArray, 1000);
   selectionSort(dupArray, 1000, count, time);
   cout << endl << "[Random array with many duplicates] - swaps: " << count << endl << "Time: " << time << " nanoseconds" << endl;
   printArray(dupArray, 1000);
   selectionSort(revArray, 1000, count, time);
   cout << endl << "[Reversely sorted array with no duplicates] - swaps: " << count << endl << "Time: " << time << " nanoseconds" << endl;
   printArray(revArray, 1000);*/
   cout << "---------END SELECTION SORT---------" << endl;
   cout << endl;

/////////////////////////////////////// Reset datasets
   //fillArray(randomArray, 1000);
   //fillAlmost(almostArray, 1000);
   //fillDup(dupArray, 1000);
   //fillRev(revArray, 1000);
//////////////////////////////////////
/////////Exchange Sort
/*
   cout << "---------START EXCHANGE SORT---------" << endl;
   exchangeSort(randomArray, 1000, count, time);
   cout << "[Random array with potential duplicates] - swaps: " << count << endl << "Time: " << time << " nanoseconds" << endl;
   printArray(randomArray, 1000);
   exchangeSort(almostArray, 1000, count, time);
   cout << endl << "[Almost sorted array with no duplicates] - swaps: " << count << endl << "Time: " << time << " nanoseconds" << endl;
   printArray(almostArray, 1000);
   exchangeSort(dupArray, 1000, count, time);
   cout << endl << "[Random array with many duplicates] - swaps: " << count << endl << "Time: " << time << " nanoseconds" << endl;
   printArray(dupArray, 1000);
   exchangeSort(revArray, 1000, count, time);
   cout << endl << "[Reversely sorted array with no duplicates] - swaps: " << count << endl << "Time: " << time << " nanoseconds" << endl;
   printArray(revArray, 1000);
   cout << "---------END EXCHANGE SORT---------" << endl;
   cout << endl;
*/
/////////////////////////////////////// Reset datasets
   //fillArray(randomArray, 1000);
   //fillAlmost(almostArray, 1000);
   //fillDup(dupArray, 1000);
   //fillRev(revArray, 1000);
//////////////////////////////////////
/////////Bubble Sort

   cout << "---------START BUBBLE SORT---------" << endl;
/*   bubbleSort(randomArray, 1000, count, time);
   cout << "[Random array with potential duplicates] - compares: " << count << endl << "Time: " << time << " nanoseconds" << endl;
   printArray(randomArray, 1000);*/
   bubbleSort(almostArray, 1000, count, time);
   cout << endl << "[Almost sorted array with no duplicates] - compares: " << count << endl << "Time: " << time << " nanoseconds" << endl;
   printArray(almostArray, 1000);
/*   bubbleSort(dupArray, 1000, count, time);
   cout << endl << "[Random array with many duplicates] - compares: " << count << endl << "Time: " << time << " nanoseconds" << endl;
   printArray(dupArray, 1000);
   bubbleSort(revArray, 1000, count, time);
   cout << endl << "[Reversely sorted array with no duplicates] - compares: " << count << endl << "Time: " << time << " nanoseconds" << endl;
   printArray(revArray, 1000);*/
   cout << "---------END BUBBLE SORT---------" << endl;
   cout << endl;

/////////////////////////////////////// Reset datasets
   //fillArray(randomArray, 1000);
   //fillAlmost(almostArray, 1000);
   //fillDup(dupArray, 1000);
   //fillRev(revArray, 1000);
//////////////////////////////////////
/////////Insertion Sort

   cout << "---------START INSERTION SORT---------" << endl;
/*   insertionSort(randomArray, 1000, count, time);
   cout << "[Random array with potential duplicates] - compares: " << count << endl << "Time: " << time << " nanoseconds" << endl;
   printArray(randomArray, 1000);
   insertionSort(almostArray, 1000, count, time);
   cout << endl << "[Almost sorted array with no duplicates] - compares: " << count << endl << "Time: " << time << " nanoseconds" << endl;
   printArray(almostArray, 1000);*/
   insertionSort(dupArray, 1000, count, time);
   cout << endl << "[Random array with many duplicates] - compares: " << count << endl << "Time: " << time << " nanoseconds" << endl;
   printArray(dupArray, 1000);
  /* insertionSort(revArray, 1000, count, time);
   cout << endl << "[Reversely sorted array with no duplicates] - compares: " << count << endl << "Time: " << time << " nanoseconds" << endl;
   printArray(revArray, 1000);*/
   cout << "---------END INSERTION SORT---------" << endl;
   cout << endl;

/////////////////////////////////////// Reset datasets
   //fillArray(randomArray, 1000);
   //fillAlmost(almostArray, 1000);
   //fillDup(dupArray, 1000);
   //fillRev(revArray, 1000);
//////////////////////////////////////
/////////Merge Sort

   cout << "---------START MERGE SORT---------" << endl;
   count = 0;
   mergeSort(randomArray, 0, 999, count, time);
   cout << "[Random array with potential duplicates] - compares: " << count << endl << "Time: " << time << " nanoseconds" << endl;
   printArray(randomArray, 1000);
   count = 0;
   mergeSort(almostArray, 0, 999, count, time);
   cout << endl << "[Almost sorted array with no duplicates] - compares: " << count << endl << "Time: " << time << " nanoseconds" << endl;
   printArray(almostArray, 1000);
   count = 0;
   mergeSort(dupArray, 0, 999, count, time);
   cout << endl << "[Random array with many duplicates] - compares: " << count << endl << "Time: " << time << " nanoseconds" << endl;
   printArray(dupArray, 1000);
   count = 0;
   mergeSort(revArray, 0, 999, count, time);
   cout << endl << "[Reversely sorted array with no duplicates] - compares: " << count << endl << "Time: " << time << " nanoseconds" << endl;
   printArray(revArray, 1000);
   cout << "---------END MERGE SORT---------" << endl;
   cout << endl;

/////////////////////////////////////// Reset datasets
   //fillArray(randomArray, 1000);
   //fillAlmost(almostArray, 1000);
   //fillDup(dupArray, 1000);
   //fillRev(revArray, 1000);
//////////////////////////////////////
/////////Quick Sort

   cout << "---------START QUICK SORT---------" << endl;
   count = 0;
   quickSort(randomArray, 0, 999, count, time);
   cout << "[Random array with potential duplicates] - compares: " << count << endl << "Time: " << time << " nanoseconds" << endl;
   printArray(randomArray, 999);
   count = 0;
   quickSort(almostArray, 0, 999, count, time);
   cout << endl << "[Almost sorted array with no duplicates] - compares: " << count << endl << "Time: " << time << " nanoseconds" << endl;
   printArray(almostArray, 1000);
   count = 0;
   quickSort(dupArray, 0, 999, count, time);
   cout << endl << "[Random array with many duplicates] - compares: " << count << endl << "Time: " << time << " nanoseconds" << endl;
   printArray(dupArray, 1000);
   count = 0;
   quickSort(revArray, 0, 999, count, time);
   cout << endl << "[Reversely sorted array with no duplicates] - compares: " << count << endl << "Time: " << time << " nanoseconds" << endl;
   printArray(revArray, 1000);
   cout << "---------END QUICK SORT---------" << endl;
   cout << endl;

/////////////////////////////////////// Reset datasets
   //fillArray(randomArray, 1000);
   //fillAlmost(almostArray, 1000);
   //fillDup(dupArray, 1000);
   //fillRev(revArray, 1000);
//////////////////////////////////////
/////////Heap Sort

   cout << "---------START HEAP SORT---------" << endl;
   count = 0;
   heapSort(randomArray, 1000, count, time);
   cout << "[Random array with potential duplicates] - compares: " << count << endl << "Time: " << time << " nanoseconds" << endl;
   printArray(randomArray, 1000);
   count = 0;
   heapSort(almostArray, 1000, count, time);
   cout << endl << "[Almost sorted array with no duplicates] - compares: " << count << endl << "Time: " << time << " nanoseconds" << endl;
   printArray(almostArray, 1000);
   count = 0;
   heapSort(dupArray, 1000, count, time);
   cout << endl << "[Random array with many duplicates] - compares: " << count << endl << "Time: " << time << " nanoseconds" << endl;
   printArray(dupArray, 1000);
   count = 0;
   heapSort(revArray, 1000, count, time);
   cout << endl << "[Reversely sorted array with no duplicates] - compares: " << count << endl << "Time: " << time << " nanoseconds" << endl;
   printArray(revArray, 1000);
   cout << "---------END HEAP SORT---------" << endl;
   cout << endl;

////////////////////////////////////////////////////////////////////////////////
   return 0;
}
/*void load(int myArray[])
{
   ifstream inFile;
   string line;
   inFile.open("data.txt");
   inFile >> line;
   for (int i = 0; i<line.length(); i++)
   {
      if (line[i] == ",")
      {
         
      }
   inFile.close();
}*/
void printArray(int myArray[], int arraySize)
{
   for (int i = 0; i<arraySize; i++)
   {
      if (i == arraySize-1)
         cout << myArray[i] << endl;
      else
         cout << myArray[i] << ", ";
   }
}

void swap(int &x, int &y)
{
   int temp = x;
   x = y;
   y = temp;
}

void selectionSort(int x[], int n, int &count, double &time)
{
   count = 0;
   int i, j, smallest;
   auto start = chrono::steady_clock::now();
   for(i = 0; i < n-1; i++)
   {
      smallest = i;
      for(j = i+1; j < n; j++)
      {
         count++;
         if(x[smallest] > x[j])
            smallest = j;
      }
      //count++; SWAPS
      swap(x[i],x[smallest]);
   }
   auto end = chrono::steady_clock::now();
   time = double(chrono::duration_cast <chrono::nanoseconds> (end-start).count());
}
void bubbleSort(int x[], int n, int &count, double &time)
{
   auto start = chrono::steady_clock::now();
   count = 0;
   int i, j;
   for(i = 0; i<n-1; i++)
   {
      for(j = 0; j<n-i-1; j++)
      {
         if(x[j]>x[j+1])
         {
            count++;
            swap(x[j], x[j+1]);
         }
      }
   }
   auto end = chrono::steady_clock::now();
   time = double(chrono::duration_cast <chrono::nanoseconds> (end-start).count());
}
void mergeSort(int array[], int const begin, int const end, int &count, double &time)
{
    auto start = chrono::steady_clock::now();
    if (begin >= end)
        return; // Returns recursively
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid, count, time);
    mergeSort(array, mid + 1, end, count, time);
    merge(array, begin, mid, end, count);
    auto endt = chrono::steady_clock::now();
    time = double(chrono::duration_cast <chrono::nanoseconds> (endt-start).count());
}
void merge(int array[], int const left, int const mid, int const right, int &count)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
  
    // Create temp arrays
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
  
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
  
    auto indexOfSubArrayOne = 0, // Initial index of first sub-array
        indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array
  
    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
        {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else 
        {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
        count++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) 
    {
        count++;
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) 
    {
        count++;
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void exchangeSort(int myArray[], int arraySize, int &count, double &time)
{
   auto start = chrono::steady_clock::now();
   int temp;
   count = 0;
   for (int x=0; x<arraySize-1; x++)
   {
      for (int j=0; j<arraySize-1; j++)
      {
         if (myArray[j] > myArray[j+1])
         {
            count++;
            temp = myArray[j];
            myArray[j] = myArray[j+1];
            myArray[j+1] = temp;
         }
      }
   }  
   auto end = chrono::steady_clock::now();
   time = double(chrono::duration_cast <chrono::nanoseconds> (end-start).count());
}

void quickSort(int arr[], int low, int high, int &count, double &time)
{
    auto start = chrono::steady_clock::now();
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now 
        at right place */
        int pi = partition(arr, low, high, count);
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1, count, time);
        quickSort(arr, pi + 1, high, count, time);
    }
    auto end = chrono::steady_clock::now();
    time = double(chrono::duration_cast <chrono::nanoseconds> (end-start).count());
}

int partition (int arr[], int low, int high, int &count)
{
    int pivot = arr[high]; // pivot 
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot 
        count++;
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element 
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);//here
    return (i + 1);
}

void insertionSort(int arr[], int n, int &count, double &time)
{
   auto start = chrono::steady_clock::now();
   count = 0;
   int i, key, j;
   for (i = 1; i < n; i++)
   {
      key = arr[i];
      j = i - 1;
      /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
      while (j >= 0 && arr[j] > key)
      {
         count++;
         arr[j + 1] = arr[j];
         j = j - 1;
      }
      arr[j + 1] = key;
   }
   auto end = chrono::steady_clock::now();
   time = double(chrono::duration_cast <chrono::nanoseconds> (end-start).count());
}

void heapSort(int arr[], int n, int &count, double &time)
{
    auto start = chrono::steady_clock::now();
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, count);
 
    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) 
    {
        // Move current root to end
        swap(arr[0], arr[i]);
        // call max heapify on the reduced heap
        heapify(arr, i, 0, count);
    }
    auto end = chrono::steady_clock::now();
    time = double(chrono::duration_cast <chrono::nanoseconds> (end-start).count());
}
void heapify(int arr[], int n, int i, int &count)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    count++;
    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }
 
    // If right child is larger than largest so far
    count++;
    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }
 
    // If largest is not root
    count++;
    if (largest != i) 
    {
        swap(arr[i], arr[largest]); 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest, count);
    }
}
/*
void fillArray(int myArray[], int arraySize)
{
    srand(time(0));
    for (int i = 0; i < arraySize; i++)
    {
        int numRand = rand() % 1000; //Include 1000
        myArray[i] = numRand;
    }
}

void fillAlmost(int myArray[], int arraySize)
{
   int j = 0;
   int temp = 0;
   int check = 0;
   srand(time(0));
   for (int i = 0; i < arraySize; i++)
     myArray[i] = i;
   for (int x = 0; x<arraySize; x++)
   {
      int numRand = rand()%3;
      j = numRand;

      temp = myArray[x];
      check = x+j;
      if (check < arraySize)
      {
         myArray[x] = myArray[x+j];
         myArray[x+j] = temp;
      }
   }
}

void fillDup(int myArray[], int arraySize)
{
   srand(time(0));
   int newRand = 0;
   for (int i = 0; i < arraySize; i++)
   {
      int numRand = rand() % 1000;
      myArray[i++] = numRand;
      myArray[i] = numRand;
      newRand = rand() % 10;
      if (newRand%2 == 0)
      {
         i++;
         myArray[i] = numRand;
      }
   }
}

void fillRev(int myArray[], int arraySize)
{
    int j = arraySize;
    for (int i = 0; i < arraySize; i++)
    {
        j--;
        myArray[i] = j;
    }
}*/
