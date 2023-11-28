#ifndef __STOREITEM_H__
#define __STOREITEM_H__

#include <iostream>
#include <string>
using namespace std;

class StoreItem {
public:
  string type;
  string level_names[5];
  string level_images[5];
  float level_multipliers[5];

  // Default constructor (intentionally empty)
  StoreItem() {}

  //SETTERS and GETTERS
  void setType(string n) { type = n; }
  string getType() { return type; }
  void setLevelName(int i, string n) { level_names[i-1] = n; }
  string getLevelName(int i) { return level_names[i-1]; }
  void setLevelImage(int i, string n) { level_images[i-1] = n; }
  string getLevelImage(int i) { return level_images[i-1]; }
  void setLevelMultiplier(int i, float m) { level_multipliers[i-1] = m; }
  float getLevelMultiplier(int i) { return level_multipliers[i-1]; }
};

class Store {
public:
  static const int num_items = 8;
  StoreItem items[Store::num_items];

  Store() {
    items[0].type = "Lawn Mower";

    items[0].level_names[0] = "Unpowered Mower";
    items[0].level_names[1] = "Gas Mower";
    items[0].level_names[2] = "Self-Propelled Gas Mower";
    items[0].level_names[3] = "Riding Gas Mower";
    items[0].level_names[4] = "Totally unneccessary V8 Mower";

    items[0].level_multipliers[0] = 1.05;
    items[0].level_multipliers[1] = 1.10;
    items[0].level_multipliers[2] = 1.15;
    items[0].level_multipliers[3] = 1.20;
    items[0].level_multipliers[4] = 1.25;

    items[0].level_images[0] = "https://m.media-amazon.com/images/I/71HGrPB7y2L._AC_SL1500_.jpg";
    items[0].level_images[1] = "http://mobileimages.lowes.com/productimages/62e549a6-6611-4518-b77d-f6f6fb74064d/12158334.jpg";
    items[0].level_images[2] = "https://mobileimages.lowes.com/productimages/fe4853b5-9cb1-4999-b7bc-882fcc7273a4/16145850.jpg?size=pdhism";
    items[0].level_images[3] = "http://mobileimages.lowes.com/productimages/85f56cb0-d4a6-4159-82ba-29b3ae62e8bf/08568264.jpg";
    items[0].level_images[4] = "https://i.pinimg.com/originals/16/54/4c/16544c602d2106fb584af71bcec80a1f.jpg";

    ////////////////
    items[1].type = "Leaf Blower";

    items[1].level_names[0] = "A rake";
    items[1].level_names[1] = "Plug-in leaf blower";
    items[1].level_names[2] = "Battery leaf blower";
    items[1].level_names[3] = "Backpack leaf blower";
    items[1].level_names[4] = "Zephyrus, god of the west wind";

    items[1].level_multipliers[0] = 1.05;
    items[1].level_multipliers[1] = 1.10;
    items[1].level_multipliers[2] = 1.15;
    items[1].level_multipliers[3] = 1.20;
    items[1].level_multipliers[4] = 1.25;

    items[1].level_images[0] = "https://m.media-amazon.com/images/I/61G6WW1UepL._AC_SL1500_.jpg";
    items[1].level_images[1] = "https://m.media-amazon.com/images/I/51qn2B2h77L._AC_SL1200_.jpg";
    items[1].level_images[2] = "https://mobileimages.lowes.com/productimages/6f544f1b-4195-4fbe-96ed-4c9cbdea0626/00577697.jpg?size=pdhism";
    items[1].level_images[3] = "https://images.thdstatic.com/productImages/ddd2ac82-4ee5-4c33-89a9-e0826c6ca394/svn/troy-bilt-gas-leaf-blowers-tb51bp-64_600.jpg";
    items[1].level_images[4] = "https://i.ytimg.com/vi/CDaBwKlvH98/mqdefault.jpg";

    ////////////////
    items[2].type = "Snow Blower";

    items[2].level_names[0] = "A shovel";
    items[2].level_names[1] = "Basic single stage snow blower";
    items[2].level_names[2] = "Solid 2-stage snow blower";
    items[2].level_names[3] = "Superfast 3-stage snow blower";
    items[2].level_names[4] = "Snowplow";

    items[2].level_multipliers[0] = 1.05;
    items[2].level_multipliers[1] = 1.10;
    items[2].level_multipliers[2] = 1.15;
    items[2].level_multipliers[3] = 1.20;
    items[2].level_multipliers[4] = 1.25;

    items[2].level_images[0] = "https://i5.walmartimages.com/asr/9cbf3a21-f33a-4ccb-8b98-0a17ee546dd0_1.b0987cbf025ad6cdc063748481ea159b.jpeg?odnHeight=612&odnWidth=612&odnBg=FFFFFF";
    items[2].level_images[1] = "https://i5.walmartimages.com/asr/4bed30e9-c9b4-43de-8235-b6c7d089a5de.61fb29e583ded8f7763b89f7185d2a7b.jpeg";
    items[2].level_images[2] = "https://images.thdstatic.com/productImages/a8790ced-198c-49f1-8229-26d5f15af741/svn/troy-bilt-two-stage-snow-blowers-storm-2410-64_1000.jpg";
    items[2].level_images[3] = "http://mobileimages.lowes.com/productimages/f6c33083-6144-46ec-810b-6b52dc8eb0bf/03842940.jpg";
    items[2].level_images[4] = "https://www.familyhandyman.com/wp-content/uploads/2019/02/shutterstock_644609866-Plow.jpg?fit=696,696";

    ////////////////
    items[3].type = "Hedge Trimmer";

    items[3].level_names[0] = "Pruning shears";
    items[3].level_names[1] = "Loppers";
    items[3].level_names[2] = "Basic hedge trimmer";
    items[3].level_names[3] = "Commercial hedge trimmer";
    items[3].level_names[4] = "Hydraulic tractor trimmer";

    items[3].level_multipliers[0] = 1.05;
    items[3].level_multipliers[1] = 1.10;
    items[3].level_multipliers[2] = 1.15;
    items[3].level_multipliers[3] = 1.20;
    items[3].level_multipliers[4] = 1.25;

    items[3].level_images[0] = "https://m.media-amazon.com/images/I/71JCbL0LNDL._AC_SL1479_.jpg";
    items[3].level_images[1] = "https://www.amleo.com/media/catalog/product/cache/aa1841770a2aa8b05bb5b429e42f9ba2/a/m/aml24.jpg";
    items[3].level_images[2] = "https://m.media-amazon.com/images/I/51ma+8ZTzOS._AC_SX425_.jpg";
    items[3].level_images[3] = "https://www.powerequipmentwarehouse.com/images/thumbs/0019197_hs82t-24-stihl-227cc-24-double-edge-pro-hedge-trimmer-with-rear-swivel-handle_510.jpeg";
    items[3].level_images[4] = "https://www.esm-ept.de/fileadmin/user_upload/Alternativtextbilder/hs.jpg";

    ////////////////
    items[4].type = "Grill";

    items[4].level_names[0] = "Fire pit";
    items[4].level_names[1] = "Charcoal kettle grill";
    items[4].level_names[2] = "Gas grill";
    items[4].level_names[3] = "Combination smoker grill";
    items[4].level_names[4] = "Built-in grill smoker and oven";

    items[4].level_multipliers[0] = 1.05;
    items[4].level_multipliers[1] = 1.10;
    items[4].level_multipliers[2] = 1.15;
    items[4].level_multipliers[3] = 1.20;
    items[4].level_multipliers[4] = 1.25;

    items[4].level_images[0] = "https://m.media-amazon.com/images/I/61oR8QlvSRL._AC_SL1000_.jpg";
    items[4].level_images[1] = "https://mobileimages.lowes.com/productimages/45669de4-fbc9-4ebc-acd4-a64ed6dd9870/08970819.jpg?size=pdhism";
    items[4].level_images[2] = "https://product-images.weber.com/Grill-Images/Gas/7470001A-REV.png?w=800&h=800&auto=compress%2Cformat";
    items[4].level_images[3] = "http://mobileimages.lowes.com/productimages/69d2a7cb-6996-45aa-a04f-e8e6f7dd07bc/12079851.jpg";
    items[4].level_images[4] = "https://resources.belgard.com/wp-content/uploads/2021/03/AMCOR_RES_BEL2016_Patios_OutdoorKitchens_Walls_LafittRusticSlab_WestonWall_Stonegate_BristolBrickOven_001_preview.jpg";

    ////////////////
    items[5].type = "Ladder";

    items[5].level_names[0] = "Upside-down crate";
    items[5].level_names[1] = "Step Stool";
    items[5].level_names[2] = "Step Ladder";
    items[5].level_names[3] = "Platform Ladder";
    items[5].level_names[4] = "Ultra-Lightweight Carbon Fiber Ladder";

    items[5].level_multipliers[0] = 1.05;
    items[5].level_multipliers[1] = 1.10;
    items[5].level_multipliers[2] = 1.15;
    items[5].level_multipliers[3] = 1.20;
    items[5].level_multipliers[4] = 1.25;

    items[5].level_images[0] = "https://atlas-content1-cdn.pixelsquid.com/assets_v2/12/1206014986363606995/jpeg-600/G15.jpg";
    items[5].level_images[1] = "https://i5.walmartimages.com/asr/a2d09d3a-8ed4-4ea2-9d52-5b6553fe2092_1.7ee3938b1476efd58a111aac2be675c6.jpeg";
    items[5].level_images[2] = "https://www.bhphotovideo.com/images/images1000x1000/Matthews_549131_Double_Sided_Ladder_144453.jpg";
    items[5].level_images[3] = "https://images.thdstatic.com/productImages/660bbc85-e010-42f7-87da-b28307c6f2d4/svn/werner-platform-ladders-pdia04-64_1000.jpg";
    items[5].level_images[4] = "https://images.food52.com/yKNCP4r35FtHxTb2PXraYen19A8=/188x188/0194c0d9-b022-4aa3-bcaa-fdf669953ffa--2020-0713_hasegawa_lucano-lightweight-step-ladder_4-step-black_silo_ty-mecham.jpg";

    ////////////////
    items[6].type = "Tools";

    items[6].level_names[0] = "Swiss army knife";
    items[6].level_names[1] = "Toolbox";
    items[6].level_names[2] = "Tool cabinet";
    items[6].level_names[3] = "Tool bench";
    items[6].level_names[4] = "Entire garage";

    items[6].level_multipliers[0] = 1.05;
    items[6].level_multipliers[1] = 1.10;
    items[6].level_multipliers[2] = 1.15;
    items[6].level_multipliers[3] = 1.20;
    items[6].level_multipliers[4] = 1.25;

    items[6].level_images[0] = "https://imageengine.victorinox.com/mediahub/39710/640Wx560H/SAK_1_3713__S1.jpg";
    items[6].level_images[1] = "https://www.harborfreight.com/media/catalog/product/cache/9fc4a8332f9638515cd199dd0f9238da/9/1/91111_W3.jpg";
    items[6].level_images[2] = "https://mobileimages.lowes.com/product/converted/GR_267/GR_267_16728289.jpg?size=cdp";
    items[6].level_images[3] = "https://images.thdstatic.com/productImages/7d9c29b9-507e-4be1-8db7-183a4aa56784/svn/red-and-black-matte-finish-milwaukee-mobile-workbenches-48-22-8561-1d_600.jpg";
    items[6].level_images[4] = "https://www.snaplap.net/wp-content/uploads/2021/07/garage-workshop.jpeg";

    ////////////////
    items[7].type = "Chair";

    items[7].level_names[0] = "Cloth chair";
    items[7].level_names[1] = "Leather chair";
    items[7].level_names[2] = "Leather recliner";
    items[7].level_names[3] = "Leather massage chair";
    items[7].level_names[4] = "Dad throne";

    items[7].level_multipliers[0] = 1.05;
    items[7].level_multipliers[1] = 1.10;
    items[7].level_multipliers[2] = 1.15;
    items[7].level_multipliers[3] = 1.20;
    items[7].level_multipliers[4] = 1.25;

    items[7].level_images[0] = "https://target.scene7.com/is/image/Target/GUEST_d01d7066-a4a8-4f79-af86-bf35dda01787?wid=488&hei=488&fmt=pjpeg";
    items[7].level_images[1] = "https://www.afw.com/images/thumbs/0115491_1M-4829C_2a074_600.jpeg";
    items[7].level_images[2] = "https://d12mivgeuoigbq.cloudfront.net/magento-media/catalog/product/1/8/18ac7fbf-bfd6-49e8-a4cb-c223af2dafe0.jpg?w=640";
    items[7].level_images[3] = "https://i5.walmartimages.com/asr/7e1f6a11-d0a8-4824-8e55-23aade3ee624.2ff0505b18951d5b0ab7abc9c1fda3fb.jpeg";
    items[7].level_images[4] = "https://images.thebrag.com/tb/uploads/2017/08/dennis-graham-768x393.jpg";
  }
};

// lawnmower
// snowblower
// leafblower
// hedgetrimmer
// grill
// ladder
// tools
// chair

#endif
