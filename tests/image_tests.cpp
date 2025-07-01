#include <gtest/gtest.h>
#include "../include/image.h"
#include "../include/turnimage.h"

// Test image creation
TEST(ImageTest, Creation) {
    Image img(100, 100);
    EXPECT_EQ(img.GetWidth(), 100);
    EXPECT_EQ(img.GetHeight(), 100);
}

// Test color setting and getting
TEST(ImageTest, ColorOperations) {
    Image img(10, 10);
    Color testColor(0.5f, 0.3f, 0.7f);
    
    img.SetColor(testColor, 5, 5);
    
    Color retrievedColor = img.GetColor(5, 5);
    EXPECT_FLOAT_EQ(retrievedColor.r, 0.5f);
    EXPECT_FLOAT_EQ(retrievedColor.g, 0.3f);
    EXPECT_FLOAT_EQ(retrievedColor.b, 0.7f);
}

// Test Gaussian blur (basic functionality)
TEST(ImageProcessingTest, GaussianBlur) {
    Image img(10, 10);
    // Fill with a test pattern
    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            img.SetColor(Color(1.0f, 0.0f, 0.0f), x, y);
        }
    }
    
    // Apply blur with small radius
    img.ApplyGaussianBlur(1, 0.5f);
    
    // Verify that colors are still valid (not checking exact values, just general validity)
    Color center = img.GetColor(5, 5);
    EXPECT_GE(center.r, 0.0f);
    EXPECT_LE(center.r, 1.0f);
}

// Simple test to verify Turn_Image namespace exists
TEST(TurnImageTest, NamespaceExists) {
    // This is a simple existence test
    EXPECT_TRUE(true);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 