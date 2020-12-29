#include <litequarks/litequarks.hpp>
#include "Components.hpp"

using namespace LQUnit;

DropProjectView::DropProjectView(
    LQNumber&& x, LQNumber&& y, LQNumber&& w, LQNumber&& h, GLint color)
: LQViewport(std::move(x), std::move(y), std::move(w), std::move(h), color)
{
    // ViewableBuilder builder = new ViewableBuilder();
    // builder.setActive(true);

    appendChild(new LQDocument(color));
    // add(new Document(color));
    auto* document = static_cast<LQViewable*>(firstChild());
    // Viewable* document = firstChild();

    document->appendChild(new LQViewable(0_px, 0_px, width(), 1_px));
    // document->add(new Viewable("pos: 0px, dim: parent.width 1px"));

    auto* drop = new LQDrop(
        0.20f * width(), 100_px, 0.60f * width(), 350_px, 0xE9E9E9);

    // builder.declare("dropview", this);
    // builder.declareNextAs("drop", "text2", "text");

    // DropArea drop = new Drop(
    //     "pos: (0.2 * dropview.width) 100px,"
    //     "dim: (0.6 * dropview.width) 350px,"
    //     "color: #e9e9e9"
    // );

    auto* text2 = new LQText("votre projet", 0.0f, drop->height() / 2, 1_em, 0x808080);
    // Label text2 = new Label(
    //     "text: (votre projet),"
    //     "pos: (drop.width / 2 - this.width / 2) (drop.height / 2),"
    //     "height: 1em, color: #808080"
    // );
    auto* text = new LQText("Glissez et déposez", 0.0f, text2->top()-0.5_em, 1_em, 0x808080);
    // Label text = new Label (
    //     "text: (Glissez et déposez),"
    //     "pos: (drop.width / 2 - this.width / 2) (text2.top - 0.5em),"
    //     "height: 1em, color: #808080"
    // );
    auto* text3 = new LQText("ici", 0.0f, text2->bottom()+1.2_em, 1_em, 0x808080);
    // Label text3 = new Label (
    //     "text: (ici),"
    //     "pos: (drop.width / 2 - this.width / 2) (text2.bottom + 1.2em),"
    //     "height: 1em, color: #808080"
    // );
    text->x() = drop->width() / 2 - text->widthF() / 2;
    text2->x() = drop->width() / 2 - text2->widthF() / 2;
    text3->x() = drop->width() / 2 - text3->widthF() / 2;

    drop->appendChild(text);
    drop->appendChild(text2);
    drop->appendChild(text3);

    auto* nom = new LQTextArea(
        drop->left(), drop->bottom()+15_px, 0.60f * drop->width(),
        50_px, 0xE9E9E9, "Nom");
    auto* tag = new LQTextArea(
        nom->right() + 15_px, nom->top(), drop->width() - nom->width() - 15_px,
        50_px, 0xE9E9E9, "Tag");
    
    auto* envoyer = new LQButton(
        drop->left() + 0.30f * drop->width(), nom->bottom() + 35_px,
        0.40f * drop->width(), 50_px, 0x2f3136,"Envoyer", 0xffffff,
        [drop, nom, tag]() {
            std::string path = drop->getPath();
            std::string strNom = nom->getContent();
            std::string strTag = tag->getContent();
            auto* error2 =
                static_cast<LQViewable*>(tag->nextSibling()->nextSibling());
            auto* error = static_cast<LQViewable*>(error2->nextSibling());
            auto* valid = static_cast<LQViewable*>(error->nextSibling());
            error->hide();
            valid->hide();

            if (!path.empty() && !strNom.empty() && !strTag.empty()) {
                error2->hide();
                LQAppController::pushEvent(new upProjectEvent(
                    path, strNom, strTag, "", ""));
            }
            else {
                error2->unhide();
            }
            
        });

    auto* error2 = new LQText(
        "Veuillez remplir tous les champs", envoyer->right() + 15_px,
         envoyer->top() + envoyer->height() / 2 + 0.4_em, 1_em, 0xc93838);
    auto* error = new LQText(
        "Échec, le nom est déjà pris", envoyer->right() + 15_px,
         envoyer->top() + envoyer->height() / 2 + 0.4_em, 1_em, 0xc93838);
    auto* valid = new LQText(
        "Projet bien envoyé", envoyer->right() + 15_px,
         envoyer->top() + envoyer->height() / 2 + 0.4_em, 1_em, 0x356b34);

    error2->hide();
    error->hide();
    valid->hide();

    document->appendChild(drop);
    document->appendChild(nom);
    document->appendChild(tag);
    document->appendChild(envoyer);
    document->appendChild(error2);
    document->appendChild(error);
    document->appendChild(valid);

    static_cast<LQViewable*>(document->firstChild())->hide();
    recalc();

    // this->tree()
    // .add(new Label(
    //     "text: 'votre projet',"
    //     "pos: (drop.width / 2 - this.width / 2) (drop.height / 2),"
    //     "height: 1em, color: #808080")
    // .add(new Label(
    //     "text: 'votre projet',"
    //     "pos: (drop.width / 2 - this.width / 2) (drop.height / 2),"
    //     "height: 1em, color: #808080")
    //     // .addEventListener('mouseclick', event -> System.out.println(event.pos))
    // .childs()
    //     .add(new Label(new AttrList()
    //         .text("votre projet")
    //         .pos("drop.width / 2 - this. width / 2", "drop.height / 2")
    //         .height("1em")
    //         .color("#808080"))
    //     .parent()
    // .add(new Label(
    //     "text: 'votre projet',"
    //     "pos: (drop.width / 2 - this.width / 2) (drop.height / 2),"
    //     "height: 1em, color: #808080");
};
