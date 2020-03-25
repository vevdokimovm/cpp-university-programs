#lang racket


;; Constructor and selectors for Huffman's terminal nodes.
(define (make-leaf symbol weight)
  (list 'leaf symbol weight))

(define (leaf? object)
  (eq? (car object) 'leaf))

(define (symbol-leaf x) (cadr x))

(define (weight-leaf x) (caddr x))




;; Constructor and selectors for Huffman's vertices.
(define (make-code-tree left right)
  (list left
        right
        (append (symbols left) (symbols right))
        (+ (weight left) (weight right))))

(define (left-branch tree) (car tree))

(define (right-branch tree) (cadr tree))

(define (symbols tree)
  (if (leaf? tree)
      (list (symbol-leaf tree))
      (caddr tree)))

(define (weight tree)
  (if (leaf? tree)
      (weight-leaf tree)
      (cadddr tree)))




;; Encode given sequence of symbols.
(define (encode message tree)
  (if (null? message)
      '()
      (append (encode-symbol (car message) tree)
              (encode (cdr message) tree))))

(define (encode-symbol symbol current-branch)
  (cond ((not (symbol-in-vertex? symbol current-branch))
         (error "undefined symbol -- ENCODE-SYMBOL" symbol))
        (else
         (let ((left-b (left-branch current-branch))
               (right-b (right-branch current-branch)))
           (cond ((symbol-in-vertex? symbol left-b)
                  (leaf-branch-action 0 symbol left-b))
                 (else (leaf-branch-action 1 symbol right-b)))))))

(define (leaf-branch-action initial symbol branch)
  (if (leaf? branch)
      (list initial)
      (cons initial
            (encode-symbol symbol branch))))

(define (symbol-in-vertex? symbol branch)
  (define (checking symbol symbols branch)
    (cond ((null? symbols) #f)
          ((eq? symbol (car symbols)) #t)
          (else (checking symbol (cdr symbols) branch))))
  (checking symbol (symbols branch) branch))
         



;; Decode given sequence of bites.
(define (decode bits tree)
  (define (decode-1 bits current-branch)
    (if (null? bits)
        '()
        (let ((next-branch
               (choose-branch (car bits) current-branch)))
          (if (leaf? next-branch)
              (cons (symbol-leaf next-branch)
                    (decode-1 (cdr bits) tree))
              (decode-1 (cdr bits) next-branch)))))
  (decode-1 bits tree))

(define (choose-branch bit branch)
  (cond ((= bit 0) (left-branch branch))
        ((= bit 1) (right-branch branch))
        (else (error "плохой бит -- CHOOSE-BRANCH" bit))))




;; Add element to set. Works with ordered lists.
;; Sorts from the smallest to the largest weight.
(define (adjoin-set x set)
  (cond ((null? set) (list x))
        ((< (weight x) (weight (car set))) (cons x set))
        (else (cons (car set)
                    (adjoin-set x (cdr set))))))

;; Sort given list of pairs. Type of pair - ('symbol number).
(define (make-leaf-set pairs)
  (if (null? pairs)
      '()
      (let ((pair (car pairs)))
        (adjoin-set (make-leaf (car pair)
                               (cadr pair))
                    (make-leaf-set (cdr pairs))))))




;; Generates Huffman tree.
(define (generate-huffman-tree pairs)
  (successive-merge (make-leaf-set pairs)))

(define (successive-merge vertices)
  (if (null? (cdr vertices))
      (car vertices)
      (let ((left (car vertices))
            (right (cadr vertices)))
        (successive-merge (adjoin-set (make-code-tree left
                                                      right)
                                      (cddr vertices))))))
  




